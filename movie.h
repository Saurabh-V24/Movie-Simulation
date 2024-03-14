
#ifndef movie_hpp
#define movie_hpp

#include <iostream>
#include <vector>

using namespace std;

class Movie
{
public:
    Movie();
    Movie(char, char, string, string, int, int);
    virtual ~Movie();
    
    // overloading
    virtual bool operator==(const Movie& ) const;
    virtual bool operator!=(const Movie& ) const;
    virtual bool operator>(const Movie& ) const;
    virtual bool operator<(const Movie& ) const;
    
    // getters
    char getGenre() const;
    char getType() const;
    string getTitle() const;
    string getDirector() const;
    int getStock() const;
    int getYear() const;
    bool checkDup() const;

    virtual void display() const;
    string getMovieInfo() const;
    virtual string getActor() const;
    virtual int getMonth() const;
    
    void statusOfDup(bool);
    bool increaseStock(int );
    virtual bool decreaseStock(int );
    virtual void addDupMovies(Movie*& );
        
protected:
    string title;
    string director;
    int year; 
    char genre;
    char type;
    int stock;
    bool flag;
};


class Classic : public Movie
{
public:
    Classic(char genre, char Type, string title, string director, int stock, int year, int month, string actor);
    ~Classic();
        
    // overloading
    virtual bool operator == (const Movie&m) const;
    virtual bool operator != (const Movie&m) const;
    virtual bool operator > (const Movie&m) const;
    virtual bool operator < (const Movie&m) const;
        
    // getters
    virtual int getMonth() const;
    virtual void display() const;
    virtual string getActor() const;
    int getTotalStock() const;
        
    virtual bool subtractFromStock(int);
    virtual void addSameMovie(Movie*&);
private:
    vector<Movie*> dupMovie;
    string actor; // actor name
    int month;
};


class Comedy : public Movie
{
public:
     Comedy(char genre, char Type, string title, string director, int stock, int year);
    ~Comedy();
    // overloading
    virtual bool operator==(const Movie& m) const;
    virtual bool operator != (const Movie& m) const;
    virtual bool operator > (const Movie& m) const;
    virtual bool operator < (const Movie& m) const;
};

class Drama : public Movie
{
public:
    Drama(char genre, char Type, string title, string director, int stock, int year);
    ~Drama();
    
    // Overloaded operators
    virtual bool operator==(const Movie& m) const;
    virtual bool operator != (const Movie& m) const;
    virtual bool operator > (const Movie& m) const;
    virtual bool operator < (const Movie& m) const;
};

#endif /* movie_h */
