#ifndef Movie_h
#define Movie_h

#include <string>
#include <iostream>
#include <fstream>
#ifndef MOVIE_H
#define MOVIE_H
using namespace std;

class Movie
{
public:
    Movie();
    Movie(char movieType, int stock, string director, string title, int yearReleased);
    ~Movie();
    
    virtual void buildingData(ifstream &file);
    virtual void setTypeOfMovie(char movieType);
    virtual void setStock(int stock);
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setReleaseYear(int releaseYear);
    virtual void setMajorActor(string majorActor);
    virtual bool setReleaseMonth(int month);
    

    virtual char getTypeOfMovie() const;
    virtual int getStock() const;
    virtual string getDirector() const;
    virtual string getTitle() const;
    virtual int getReleaseYear()const;
    virtual string getMajorActor()const;
    virtual int getReleaseMonth()const;
    
    virtual bool increaseStock();
    virtual bool decreaseStock();

    virtual bool operator==(const Movie& )const = 0;
    virtual bool operator!=(const Movie& )const = 0;
    virtual bool operator>(const Movie& )const = 0;
    virtual bool operator<(const Movie& )const = 0;
    virtual Movie* operator=(const Movie& );
    virtual void display()const;
    
protected:
    char typeOfMovie;
    int stock;
    string director;
    string title;
    int yearReleased;

};

#endif