#include <string>
#include <iostream>
#include <fstream>
#ifndef DRAMA_H
#define DRAMA_H
#include "Movie.h"
using namespace std;

// test
class Drama : public Movie
{
public:
    Drama();
    Drama(int stock, string director, string title, int yearReleased);
    ~Drama();

    void buildingData(ifstream &file);
    void display();

    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<(const Movie &) const;
    Movie *operator=(const Movie &);
};
#endif 