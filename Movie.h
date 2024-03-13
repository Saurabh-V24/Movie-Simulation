#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct nodeActor{
    string majorActor;
    int stock;
    nodeActor* next;
};

class Movie
{
public:
    Movie();
    Movie(char typeOfMovie, char media, string title, string director, int stock, int yearReleased);
    virtual ~Movie();
    
    char getTypeOfMovie() const;
    char getMedia() const;
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    int getReleaseYear()const;
    virtual string getMajorActor()const;

    virtual int getReleaseMonth()const;
    string infoOfMovie(string ) const;
    void manageClassicStock(bool );
    bool statusOfClassicMovie() const;
    
    bool increaseStock(int );
    bool decreaseStock(int );
    virtual void duplicateMovies(Movie*&);

    virtual bool operator==(const Movie& );
    virtual bool operator!=(const Movie& );
    virtual bool operator>(const Movie& );
    virtual bool operator<(const Movie& );
    virtual void display()const;
    
protected:
    char typeOfMovie;
    int stock;
    string director;
    string title;
    int yearReleased;
    char media;
    bool preventDouble;

};
#endif