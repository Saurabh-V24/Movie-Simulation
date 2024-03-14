// ------------------------------------------------ movie.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/12/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Implementation of movie class, used to store movie information
//           Comedy, Drama, Classic classes are derived from Movie class
//           Classic class has additional data members compared to Movie
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#include "movie.h"
#include <stdio.h>
#include <string>
#include <iomanip>

// constructors
Movie::Movie() {}

Movie::Movie(char genre, char type, string title, string director, int stock, int year)
{
    this->genre = genre;
    this->type = type;
    this->title = title;
    this->director = director;
    this->stock = stock;
    this->year = year;
    this->counted = false;
}

Movie::~Movie() {}

// display
void Movie::display() const
{
    cout << setw(7) << getGenre() << setw(7) << getType() << setw(35) << getTitle() << setw(20) << getDirector() << setw(7)<< getYear() << setw(7) <<getStock() << endl;
}

// getters
string Movie::getMovieInfo() const
{
    string titleAndDirector;
    titleAndDirector = title + " by " + director;
    return titleAndDirector;
}

char Movie::getGenre() const
{
    return genre;
}

char Movie::getType() const
{
    return type;
}

string Movie::getDirector() const
{
    return director;
}

string Movie::getTitle() const
{
    return title;
}

int Movie::getStock() const
{
    return stock;
}

int Movie::getYear() const
{
    return year;
}

// add to stock
bool Movie::increaseStock(int s)
{
    stock += s;
    return true;
}

int Movie::getMonth() const
{
    return 0;
}

string Movie::getActor() const
{
    return "";
}

// get counted status
bool Movie::get_Cstat() const
{
    return counted;
}

// set counted status
void Movie::setC(bool c)
{
    counted = c;
}

// subtract from stock
bool Movie::decreaseStock(int c)
{
    if (stock>0 && stock>=c) {
        stock-=c;
        return true;
    }
    else return false;
}

void Movie::addSameMovies(Movie *& s) {}

// overloading
bool Movie::operator>(const Movie &m) const
{
    return this->year > m.getYear();
}

bool Movie::operator<(const Movie &m) const
{
    return this->year < m.getYear();
}

bool Movie::operator==(const Movie &m) const
{
    if (this -> title == m.title && this -> year == m.getYear()) return true;
    else return false;
}

bool Movie::operator!=(const Movie &m) const
{
    return !(*this == m);
}


//-----------------------------------Classic-----------------------------------------------

//overloading
bool Classic::operator==(const Movie & m) const
{
    if (month == m.getMonth() && year==m.getYear() && getActor()==m.getActor()) return true;
    else return false;
}

bool Classic::operator!=(const Movie & m) const
{
    return !(*this==m);
}

bool Classic::operator<(const Movie &m) const
{
    if (year < m.getYear()) return true;
    else if (year==m.getYear()) {
        if (month < m.getMonth()) return true;
        else if (month == m.getMonth() && actor < m.getActor()) return true;
    }
    return false;
}

bool Classic::operator>(const Movie &m) const
{
    if (year > m.getYear()) return true;
    else if (year==m.getYear()) {
        if (month > m.getMonth()) return true;
        else if (month == m.getMonth() && actor > m.getActor()) return true;
    }
    return false;
}

// constructor
Classic::Classic(char genre, char Type, string title, string director, int stock, int year, int month, string actor) : Movie(genre, Type, title, director, stock, year)
{
    this -> actor = actor;
    this->month = month;
}

Classic::~Classic() {}


// display
void Classic::display() const
{
    cout << setw(7) << getGenre() << setw(7) << getType() << setw(35) << getTitle() << setw(20) << getDirector() << setw(7) << getMonth() << setw(7)<< getYear() << setw(7)  << getTotalS() << endl;
    cout << setw(73) << this -> getActor() << " -------------" << setw(3) << this -> getStock() << endl;
    
    for (int i = 0; i < sameMovies.size(); i++) cout << setw(73) << sameMovies[i] -> getActor() << " -------------" << setw(3) << sameMovies[i] -> getStock() << endl;
}

// getters

int Classic::getMonth() const
{
    return this->month;
}

string Classic::getActor() const
{
    return this->actor;
}

int Classic::getTotalS() const
{
    int totalS = getStock();
    for (int i=0; i<sameMovies.size(); i++) {
        if (!sameMovies[i]->get_Cstat()) {
            totalS += sameMovies[i]->getStock();
            sameMovies[i]->setC(true);
        }
    }
    return totalS;
}

// subtract from stock
bool Classic::subtractFromStock(int c)
{
    if (stock >= c && c>0) {
        stock-=c;
        return true;
    }
    // checking for same movies
    else if (sameMovies.size()>0) {
        setC(true);
        for (int i=0; i<sameMovies.size(); i++) {
            if (!sameMovies[i]->get_Cstat() && sameMovies[i]->decreaseStock(c)) return true;
            sameMovies[i]->setC(true);
        }
        return false;
    }
    else return false;
}


// adding same movies
void Classic::addSameMovies(Movie *& m)
{
    sameMovies.push_back(m);
}



//-----------------------------------Comedy-----------------------------------------------

// constructor
Comedy::Comedy(char genre, char Type, string title, string director, int stock, int year) : Movie(genre, Type, title, director, stock, year) {}

Comedy::~Comedy() {}

// overloading
bool Comedy::operator==(const Movie &m) const
{
    if (title == m.getTitle() && year==m.getYear()) return true;
    else return false;
}

bool Comedy::operator!=(const Movie &m) const
{
    return !(*this==m);
}

bool Comedy::operator>(const Movie &m) const
{
    if (title>m.getTitle()) return true;
    else if (title==m.getTitle() && year>m.getYear()) return true;
    else return false;
}

bool Comedy::operator<(const Movie &m) const
{
    if (title<m.getTitle()) return true;
    else if (title==m.getTitle() && year<m.getYear()) return true;
    else return false;
}

//-----------------------------------Drama-----------------------------------------------


//constructor
Drama::Drama(char genre, char Type, string title, string director, int stock, int year) : Movie(genre, Type, title, director, stock, year) {}

Drama::~Drama() {}


// overloading
bool Drama::operator==(const Movie &m) const
{
    if (director == m.getDirector() && title == m.getTitle()) return true;
    else return false;
}

bool Drama::operator!=(const Movie &m) const
{
    return !(*this==m);
}

bool Drama::operator>(const Movie &m) const
{
    if (director > m.getDirector()) return true;
    else if (director == m.getDirector() && title >m.getTitle()) return true;
    else return false;
}

bool Drama::operator<(const Movie &m) const
{
    if (director < m.getDirector()) return true;
    else if (director == m.getDirector() && title <m.getTitle()) return true;
    else return false;
}

