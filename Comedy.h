#ifndef Comedy_h
#define Comedy_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
public:
    Comedy();
    Comedy(int stock, string director, string title, int yearReleased);
    ~Comedy();

    void buildingData(ifstream &file);

    void display();

    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<(const Movie &) const;
    Movie *operator=(const Movie &);
};
#endif
