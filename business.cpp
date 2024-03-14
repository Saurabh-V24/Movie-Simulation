// ------------------------------------------------ business.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/13/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Business class, reads text files to populate data structures and execute commands

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#include "business.h"
#include <limits>

using namespace std;
/**
 * Constructor
 * preconditions: none
 * postconditions: default, creates a business object
 */
Business::Business() {}
// end of constructor

/**
 * Destructor
 * preconditions: none
 * postconditions: default, deletes business object
 */
Business::~Business() {}
// end of destructor

/**
 * readCustomerFile: reads customer file
 * preconditions: ifstream is open
 * postconditions: reads customer file and adds customers to hash table
 * @param in ifstream: file to read, initialized in main.cpp
 */
void Business::readCustomerFile(ifstream &in)
{
    // initialize variables for customer info
    int id;
    string firstName, lastName, line;
    getline(in, line);
    while (!in.eof())
    {
        // read line
        stringstream readLine(line);
        // populate variables
        readLine >> id;
        readLine >> lastName;
        readLine >> firstName;
        // add customer to hash table
        customerHashTable.addCustomer(id, firstName, lastName);
        // read next line
        getline(in, line);
    }
}
// end of readCustomerFile

/**
 * readMovieFile: reads movie file, populates movie BSTs
 * preconditions: ifstream is open
 * postconditions: reads movie file and adds movies to BST
 * @param in ifstream: file to read, initialized in main.cpp
 */
void Business::readMovieFile(ifstream &in)
{
    // initialize variables for movie info
    char genre = 'Z';
    int stock = 0, month = 0, year = 0;
    string director, title, actor;

    // line to skip first line
    string line;
    getline(in, line);

    while (!in.eof())
    {
        // read line
        stringstream readLine(line);
        string s;
        // populate variables
        readLine >> s;
        genre = s[0];
        readLine >> stock;
        readLine >> s;
        // parse director and title with helper function
        director = readStringStream(readLine);
        title = readStringStream(readLine);
        // if classics initialize actor and month
        if (genre == 'C')
        {
            // parse actor and date
            readLine >> actor >> s;
            actor = actor + " " + s;
            readLine >> s;
            istringstream(s) >> month;
        }
        // other genres have same format
        readLine >> year;
        // create movie
        Movie *newM = movieFactory.factory(genre, title, director, actor, month, year, stock);
        // add movies to BST, if not added delete movie
        if (!movieTree.addMovie(newM))
        {
            delete newM;
        }
        // read next line
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
// end of readMovieFile

/**
 * readTransactionFile: reads commands file
 * preconditions: ifstream is open
 * postconditions: reads commands file and executes commands
 * @param in ifstream: file to read, initialized in main.cpp
 */
void Business::readTransactionFile(ifstream &in)
{
    // initialize variables for transaction info
    char t_type, m_type, genre;
    int id = 0, month = 0, year = 0;
    string actor, director, title, s;
    Movie *m = nullptr;
    Transaction *t = nullptr;

    // line to skip first line
    string line;
    getline(in, line);

    while (!in.eof())
    {
        stringstream readLine(line);
        // read command type, history, return, borrow
        readLine >> t_type;
        if (t_type == 'H' || t_type == 'R' || t_type == 'B')
        {
            // read customer id
            readLine >> id;
            if (t_type != 'H')
            {
                // check for invalid media type
                readLine >> m_type;
                if (m_type != 'D')
                {
                    cout << "ERROR: " << m_type << " Invalid Media Type. Try Again." << endl;
                }
                else
                {
                    // decide which movie to borrow or return
                    readLine >> genre;
                    switch (genre)
                    {
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
        // create transaction object
        t = transFactory.create(t_type, id, m);
        performTransaction(t);

        // delete transaction after use
        delete t;

        // read next line
        title = "";
        director = "";
        actor = "";
        genre = 'Z';
        year = 0;
        month = 0;
        t = nullptr;
        m = nullptr;

        getline(in, line);
    }
}

/**
 * performTransaction: performs transaction
 * preconditions: transaction is not null
 * postconditions: performs transaction
 * @param t Transaction: transaction to perform
 */
bool Business::performTransaction(Transaction *t)
{
    if (t != nullptr)
        return t->perform(movieTree, customerHashTable);
    return false;
}
// end of performTransaction

/**
 * readStringStream: reads string stream, used to help parse data
 *                   such as titles, directors, and actors
 * preconditions: none
 * postconditions: reads string stream and returns string
 * @param in stringstream: stream to read
 */
string Business::readStringStream(stringstream &in)
{
    string s, t;
    in >> s;
    // read until comma is reached
    while (s[s.size() - 1] != ',')
    {
        // read next word
        in >> t;
        // concatenate with space
        s = s + " " + t;
    }
    // remove trailing comma
    if (s[s.size() - 1] == ',')
        s = s.substr(0, s.size() - 1);
    return s;
}
// end of readStringStream