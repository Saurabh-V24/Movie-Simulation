#ifndef MovieFactory_h
#define MovieFactory_h

#include "movie.h"
#include <stdio.h>

using namespace std;

class MovieFactory
{
public:
    MovieFactory();
    ~MovieFactory();
    
    Movie* factory(char genre, string title, string director, string actor, int month, int year, int stock);
};

#endif /* movie_factory_h */
