// ------------------------------------------------ MovieFactory.h -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/08/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Header file of MovieFactory class, used to create movie objects
//           Uses factory design pattern to create movie objects
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
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

    Movie *factory(char genre, string title, string director, string actor, int month, int year, int stock);
};

#endif /* movie_factory_h */
