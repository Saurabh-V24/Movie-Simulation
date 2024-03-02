#include <string>
#include <iostream>
using namespace std;

class Movie{
public:
    Movie();
    Movie(char typeOfMovie, int stock, string director, string title, string yearReleased);
    ~Movie();

    virtual void buildingData(ifstream &file);
    virtual void setTypeOfMove(char typeOfMovie);
    virtual void setStock(int stock);
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setYearReleased(int yearReleased);
    virtual void setMajorActor(string majorActor);
    virtual void setReleaseMonth(int month);


};