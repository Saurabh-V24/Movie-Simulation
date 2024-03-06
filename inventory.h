#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Movie.h"
#include "Drama.h"
#include "classic.h"
#include "Comedy.h"
using namespace std;

class Inventory{
public: 
    Inventory();
    ~Inventory();

    void creatingInventory(string const &movie);

    void viewingDrama();
    void viewingComedy();
    void viewingClassic();

    bool searchingClassicMovie(int releaseMonth, int yearReleased, string title, Movie *&movieSelection);
    bool searchingComedyMovie(string title, int yearReleased, Movie *&movieSelection);
    bool searchingDramaMovie(string director, string title, Movie *&movieSelection);

private:
    vector<Classic> classicMovie;
    vector<Drama> dramaMovie;
    vector<Comedy> comedyMovie;

};