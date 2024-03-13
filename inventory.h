#ifndef Inventory_h
#define Inventory_h

#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <fstream>

#include "Movie.h"
#include "MovieBST.h"
#include "classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class Inventory
{
public:
    Inventory();
    ~Inventory();

    Movie* getMovie(Movie*);
    void viewInventory();
    bool doesMovieExist(Movie*);
    Movie* getMovieByTitle(int, string, int);

    bool addingMovie(Movie*& );
    // bool borrowingMovie(Movie *, string&);
    // bool returningMovie(Movie*, string&);
    void combineMovie(Movie*, int);
private:
    vector<MovieBST> typeOfMovie;
};
#endif