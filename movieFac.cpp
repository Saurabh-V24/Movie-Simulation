#include "movieFac.h"
#include "Movie.h"
#include "Drama.h"


using namespace std;

MovieFactory::MovieFactory(){
}

MovieFactory::~MovieFactory(){
}

Movie* MovieFactory::factory(char typeOfMovie, string title, string director, string majorActor, int month, int yearReleased, int stock){
    Movie* movie = nullptr;

    switch(typeOfMovie){
        case 'D':
            movie = new Drama(typeOfMovie, 'D', title, director, stock, yearReleased);
            return movie;
            break;
        case 'F':
            movie = new Comedy(typeOfMovie, 'D', title, director, stock, yearReleased);
            return movie;
            break;
        case 'C':
            movie = new Classic(typeOfMovie, 'D',title, director, stock, yearReleased, month, majorActor);
            return movie;
            break;
        default:
            cerr << "ERROR: " << typeOfMovie << " Invalid Genre. Try Again. " << endl;
            return movie;
            break;
    }
}
