#ifndef Classic_h
#define Classic_h

#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
public:
    Classic(char typeOfMovie, char media, string title, string director, int stock, int yearReleased, int month, string majorActor);
    ~Classic();
    
    virtual string getMajorActor()const;
    virtual int getReleaseMonth()const;
    int getDupStock() const; 
    virtual void addDupMovies(Movie*&);

    virtual bool decreaseStock(int);
    

    int collectingStock() const;
    virtual void display();
    virtual bool operator==(const Movie& ) const;
    virtual bool operator!=(const Movie& ) const;
    virtual bool operator>(const Movie& ) const;
    virtual bool operator<(const Movie& ) const;
    
private:
    vector<Movie*> dupMovies;
    string majorActor;
    int month;
    
};

#endif 