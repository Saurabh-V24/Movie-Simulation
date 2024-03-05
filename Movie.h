#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Movie{
public:
    Movie();
    Movie(char typeOfMovie, int stock, string director, string title, int yearReleased);
    virtual void display() const;
    virtual ~Movie();

    virtual void buildingData(ifstream &file);
    virtual void setTypeOfMovie(char typeOfMovie);
    virtual void setStock(int stock);
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setYearReleased(int yearReleased);
    virtual void setMajorActor(string majorActor);
    virtual void setReleaseMonth(int month);

    virtual char getTypeOfMovie() const;
    virtual int getStock() const;
    virtual string getDirector() const;
    virtual string getTitle() const ;
    virtual int getYearReleased() const;
    virtual string getMajorActor() const;
    virtual int getReleaseMonth() const;


    // virtual bool operator==(const Movie& )const = 0;
    // virtual bool operator!=(const Movie& )const = 0;
    // virtual bool operator>(const Movie& )const = 0;
    // virtual bool operator<(const Movie& )const = 0;
    // virtual bool operator==(const Movie& )const;
    // virtual bool operator!=(const Movie& )const;
    // virtual bool operator>(const Movie& )const;
    // virtual bool operator<(const Movie& )const;
    // virtual Movie* operator=(const Movie& );

    virtual bool increaseStock();
    virtual bool decreaseStock();

protected:
    int month;
    string majorActor;
    char typeOfMovie;
    int stock;
    string director;
    string title;
    int yearReleased;
};