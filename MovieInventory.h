#ifndef MovieInventory_hpp
#define MovieInventory_hpp

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
    
    Movie* getMovie(Movie* m);
    bool if_movie_exists(Movie* m);
    void printInventory();
    
    Movie* getMovieByTitle(int, string, int);
    
    bool addMovie(Movie*& m);
    bool borrowMovie(Movie* m, string&);
    bool returnMovie(Movie* m, string&);
    
    void addAllSameM(Movie* m, int s);
private:
    // 3 BSTs. One for each type of movie 
    vector<BST> typeOfMovie;
};

#endif /* MovieInventory_h */
