#include "business.h"
#include <limits>

using namespace std;

Business::Business() {}
Business::~Business() {}

// reading customers
void Business::readCustomerFile(ifstream & in)
{
    int id;
    string firstName, lastName, line;
    getline(in, line);
    while (!in.eof()) {
        // read line
        stringstream readLine(line);
        readLine >> id;
        readLine >> lastName;
        readLine >> firstName;
        hashTable.addCustomer(id, firstName, lastName);
        getline(in, line);
    }
}

// reading movies
void Business::readMovieFile(ifstream &in)
{
    char genre = 'Z';
    int stock=0, month=0, year=0;
    string director, title, actor;
    
    string line;
    getline(in, line);
    
    while (!in.eof()) {
        // movie info
        stringstream readLine(line);
        string s;
        readLine >> s;
        genre = s[0];
        readLine >> stock;
        readLine >> s;
        director = readStringStream(readLine);
        title = readStringStream(readLine);
        // if classics -> more info
        if (genre == 'C') {
            readLine >> actor >> s;
            actor = actor + " " + s;
            readLine >> s;
            istringstream(s) >> month;
        }
        readLine >> year;
        // create movie
        Movie *newM = movieFactory.factory(genre, title, director, actor, month, year, stock);
        // no memory leaks
        if (!movieTree.addMovie(newM)) delete newM;
        title = "";
        director = "";
        actor = "";
        genre = 'Z';
        stock = 0;
        year = 0;
        month = 0;
        
        getline(in, line);
    }
}

// reading commands
void Business::readTransactionFile(ifstream &in)
{
    char t_type, m_type, genre;
    int id= 0, month=0, year=0;
    string actor, director, title, s;
    Movie* m=nullptr;
    Transaction* t=nullptr;
    
    string line;
    getline(in, line);
    
    while (!in.eof()) {
        stringstream readLine(line);
        readLine >> t_type; // command type. H - history, R - return, B - borrow
        if (t_type=='H' || t_type=='R' || t_type=='B') {
            readLine >> id; // customer id
            if (t_type != 'H') {
                readLine >> m_type;
                if (m_type!='D') {
                    cout << "ERROR: " << m_type << " Invalid Media Type. Try Again." << endl;
                }
                else {
                    // which movie to borrow/return
                    readLine >> genre;
                    switch (genre) {
                        case 'F':
                            title = readStringStream(readLine);
                            readLine >> year;
                            break;
                        case 'D':
                            director = readStringStream(readLine);
                            title = readStringStream(readLine);
                            break;
                        case 'C':
                            readLine >> month >> year;
                            readLine >> actor >> s;
                            actor = actor + " " + s;
                            break;
                    }
                    // create temp movie to work with
                    m = movieFactory.factory(genre, title, director, actor, month, year, 0);
                }
            }
        }
        // create transaction
        t = transFactory.factory(t_type, id, m);
        performTransaction(t);
        
        // no memory leaks
        delete t;
        
        title = "";
        director = "";
        actor = "";
        genre = 'Z';
        year = 0;
        month = 0;
        t = nullptr;
        m = nullptr;
        
        getline(in,line);
    }
}

// do transaction
bool Business::performTransaction(Transaction *t)
{
    if (t!=nullptr) return t->perform(movieTree, hashTable);
    return false;
}

// string stream
string Business::readStringStream(stringstream &in)
{
    string s, t;
    in >> s;
    while (s[s.size()-1] != ',') {
        in >> t;
        s = s+" "+t;
    }
    if (s[s.size()-1]==',') s=s.substr(0,s.size()-1);
    return s;
}
