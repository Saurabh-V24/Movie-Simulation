#ifndef MovieFac_H
#define MovieFac_H

#include "Movie.h"
#include <stdio.h>
#include "Drama.h"
#include "classic.h"
#include "Comedy.h"

using namespace std;

class MovieFactory{
public:
    MovieFactory();
    ~MovieFactory();
    Movie* factory(char typeOfMovie, string title, string director, string majorActor, int month, int yearReleased, int stock);
};
#endif
