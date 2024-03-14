// ------------------------------------------------ MovieInventory.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/10/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Header file of MovieInventory class, used to store movie objects
//           Uses BST to store movies of different genres, each tree is a different genre
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#ifndef MovieInventory_hpp
#define MovieInventory_hpp

#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "BST.h"
#include "movie.h"

class MovieInventory
{
public:
    MovieInventory();
    ~MovieInventory();

    Movie *getMovie(Movie *m);
    bool if_movie_exists(Movie *m);
    void printInventory();

    Movie *getMovieByTitle(int, string, int);

    bool addMovie(Movie *&m);
    bool borrowMovie(Movie *m, string &);
    bool returnMovie(Movie *m, string &);

    void addAllSameM(Movie *m, int s);
    void aggregateClassicStock(BST &classicTree);

private:
    // 3 BSTs. One for each type of movie
    vector<BST> movieType;
};

#endif /* MovieInventory_h */
