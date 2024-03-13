#ifndef Drama_H
#define Drama_H

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Drama : public Movie
{
public:
    Drama(char typeOfMovie, char media, string title, string director, int stock, int year);
    ~Drama();    
    virtual bool operator==(const Movie& ) const;
    virtual bool operator!=(const Movie& ) const;
    virtual bool operator>(const Movie& ) const;
    virtual bool operator<(const Movie& ) const;
};
#endif 