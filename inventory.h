#ifndef Inventory_h
#define Inventory_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Movie.h"
#include "classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class Inventory
{
public:
    Inventory();
    ~Inventory();

    void buildInventory(string const &movie);

    void viewingClassic();
    void viewingComedy();
    void viewingDrama();
    void viewingInventory();

    bool searchingClassic(int month, int year, string title, Movie *&movie);
    bool searchingComedy(string title, int releaseYear, Movie *&movie);
    bool searchingDrama(string director, string title, Movie *&movie);

private:
    vector<Classic> classic;
    vector<Comedy> comedy;
    vector<Drama> drama;
};
#endif