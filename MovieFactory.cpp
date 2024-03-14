#include "MovieFactory.h"
#include "movie.h"

using namespace std;

MovieFactory::MovieFactory() {}

MovieFactory::~MovieFactory() {}


Movie* MovieFactory::factory(char genre, string title, string director, string actor, int month, int year, int stock)
{
    Movie* newM = nullptr;
    switch (genre) {
        case 'F': 
            newM = new Comedy(genre, 'D', title, director, stock, year);
            return newM;
            break;
        case 'D': 
            newM = new Drama(genre, 'D', title, director, stock, year);
            return newM;
            break;
        case 'C': 
            newM = new Classic(genre, 'D', title, director, stock, year, month, actor);
            return newM;
            break;
        default:
            cerr << "ERROR: " << genre << " Genre Not Found. Try Again." << endl;
            return newM;
            break;
    }
}
