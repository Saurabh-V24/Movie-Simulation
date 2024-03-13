#ifndef Comedy_h
#define Comedy_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
public:
    Comedy(char genre, char typeOfMovie, string title, string director, int stock, int yearReleased);
    ~Comedy();
    virtual bool operator==(const Movie& ) const;
    virtual bool operator!=(const Movie& ) const;
    virtual bool operator>(const Movie& ) const;
    virtual bool operator<(const Movie& ) const;
};
#endif 
