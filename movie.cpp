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
    this->flag = false;
}

Movie::~Movie() {}

// display
void Movie::display() const
{
    cout << setw(7) << getGenre() << setw(7) << getType() << setw(35) << getTitle() << setw(20) << getDirector() << setw(7)<< getYear() << setw(7) << getStock() << endl;
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
bool Movie::increaseStock(int increment)
{
    stock += increment;
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
bool Movie::checkDup() const
{
    return flag;
}

// set counted status
void Movie::statusOfDup(bool dup)
{
    flag = dup;
}

// subtract from stock
bool Movie::decreaseStock(int decrement)
{
    if (stock>0 && stock>=decrement) {
        stock-=decrement;
        return true;
    }
    else{
        return false;
    }
}

void Movie::addDupMovies(Movie *& movie) {}

// overloading
bool Movie::operator>(const Movie &movie) const
{
    return this->year > movie.getYear();
}

bool Movie::operator<(const Movie &movie) const
{
    return this->year < movie.getYear();
}

bool Movie::operator==(const Movie &movie) const
{
    if (this -> title == movie.title && this -> year == movie.getYear()){
        return true;
    }
    else{
        return false;
    } 
}

bool Movie::operator!=(const Movie &m) const
{
    return !(*this == m);
}


//-----------------------------------Classic-----------------------------------------------

//overloading
bool Classic::operator==(const Movie &movie) const
{
    if (month == movie.getMonth() && year==movie.getYear() && getActor()==movie.getActor()){
        return true;
    }
    else{
        return false;
    } 
}

bool Classic::operator!=(const Movie & movie) const
{
    return !(*this==movie);
}

bool Classic::operator<(const Movie &movie) const
{
    if (year < movie.getYear()){
        return true;
    } 
    else if (year==movie.getYear()) {
        if (month < movie.getMonth()){
            return true;
        }
        else if (month == movie.getMonth() && actor < movie.getActor()){
            return true;
        } 
    }
    return false;
}

bool Classic::operator>(const Movie &movie) const
{
    if (year > movie.getYear()){
        return true;
    }
    else if (year==movie.getYear()) {
        if (month > movie.getMonth()){
            return true;
        } 
        else if (month == movie.getMonth() && actor > movie.getActor()){
            return true;
        } 
    }
    return false;
}

// constructor
Classic::Classic(char genre, char type, string title, string director, int stock, int year, int month, string actor) : Movie(genre, type, title, director, stock, year)
{
    this->actor = actor;
    this->month = month;
}

Classic::~Classic() {}


// display
void Classic::display() const
{
    cout << setw(7) << getGenre() << setw(7) << getType() << setw(35) << getTitle() << setw(20) << getDirector() << setw(7) << getMonth() << setw(7)<< getYear() << setw(7)  << getTotalStock() << endl;
    cout << setw(73) << this -> getActor() << " -------------" << setw(3) << this -> getStock() << endl;
    
    for (int i = 0; i < dupMovie.size(); i++) cout << setw(73) << dupMovie[i] -> getActor() << " -------------" << setw(3) << dupMovie[i] -> getStock() << endl;
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

int Classic::getTotalStock() const
{
    int currentStock = getStock();
    for (int i=0; i<dupMovie.size(); i++) {
        if (!dupMovie[i]->checkDup()) {
            currentStock += dupMovie[i]->getStock();
            dupMovie[i]->statusOfDup(true);
        }
    }
    return currentStock;
}

// subtract from stock
bool Classic::subtractFromStock(int other)
{
    if (stock >= other && other > 0) {
        stock-=other;
        return true;
    }
    else if (dupMovie.size()>0) {
        statusOfDup(true);
        for (int i=0; i<dupMovie.size(); i++) {
            if (!dupMovie[i]->checkDup() && dupMovie[i]->decreaseStock(other)) return true;
            dupMovie[i]->statusOfDup(true);
        }
        return false;
    }
    else{
        return false;
    } 
}


// adding same movies
void Classic::addSameMovie(Movie *& movie)
{
    dupMovie.push_back(movie);
}


// constructor
Comedy::Comedy(char genre, char Type, string title, string director, int stock, int year) : Movie(genre, Type, title, director, stock, year) {}

Comedy::~Comedy() {}

// overloading
bool Comedy::operator==(const Movie &movie) const
{
    if (title == movie.getTitle() && year==movie.getYear()){
        return true;
    }
    else{
        return false;
    }
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

