#include "MovieInventory.h"
#include <iomanip>

using namespace std;

// constructor
MovieInventory::MovieInventory()
{
    BST comedy; 
    BST classic;
    BST drama;
    typeOfMovie.push_back(comedy);
    typeOfMovie.push_back(classic);
    typeOfMovie.push_back(drama);
}

// destructor
MovieInventory::~MovieInventory()
{
    typeOfMovie.clear();
}

// get the movie from BST
Movie* MovieInventory::getMovie(Movie *m)
{
    Movie *fd = nullptr;
    switch (m->getGenre()) {
        case 'F': // Comedy
            typeOfMovie[0].getMovie(*m, fd);
            return fd;
            break;
        case 'D': // Drama
            typeOfMovie[1].getMovie(*m, fd);
            return fd;
            break;
        case 'C': // Classics
            typeOfMovie[2].getMovie(*m, fd);
            return fd;
            break;
            
        default:
            fd = nullptr;
            break;
    }
    return fd;
}

// check if there is such movie in BST
bool MovieInventory::if_movie_exists(Movie *m)
{
    Movie* fd = getMovie(m);
    if (fd!=nullptr) return true;
    else return false;
}

// print the inventory
void MovieInventory::printInventory()
{
    for (int i=0; i<typeOfMovie.size(); i++) {
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        switch (i) {
            case 0:
                cout << "Comedies:" << endl << endl;
                cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20)
                << "Director" << setw(7) << "Year" << setw(7) << "Stock" << endl;
                break;
            
            case 1:
                cout << "Dramas:" << endl << endl;
                cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20)
                << "Director" << setw(7) << "Year" << setw(7) << "Stock" << endl;
                break;
                
            case 2:
                cout << "Classics:" << endl << endl;
                cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20)
                << "Director" << setw(8) << "Month" << setw(7)<< "Year" << setw(7)  << "Stock" << endl;
                break;
            default:
                break;
        }
        cout << typeOfMovie[i];
        typeOfMovie[i].reset();
    }
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    
}

// add movie to the inventory
bool MovieInventory::addMovie(Movie *&movie)
{
    bool checkAdd = false;
    if (movie) {
        switch (movie->getGenre()) {
            case 'F': // Comedy
                checkAdd = typeOfMovie[0].addMovie(movie);
                return checkAdd;
                break;
                
            case 'C': // Classics
                checkAdd = typeOfMovie[2].addMovie(movie);
                if (checkAdd) // insert pointers to the same movies with different actors
                {
                    movie -> statusOfDup(true);
                    addAllSameM(movie, 1);
                    typeOfMovie[2].reset();
                }
                return checkAdd;
                break;
                
            case 'D': // Drama
                checkAdd = typeOfMovie[1].addMovie(movie);
                return checkAdd;
                break;
                
            default:
                return checkAdd;
                break;
        }
    }
    return checkAdd;
}
// borrow movie
bool MovieInventory::borrowMovie(Movie *movie, string & info)
{
    bool good = false;
    // if movie exists
    if (if_movie_exists(movie)) {
        Movie* borrow = getMovie(movie);
        if (borrow->decreaseStock(1)) { // update stock
            info = borrow->getMovieInfo();  // get info
            good = true;
        }
    }
    for (auto &movie : typeOfMovie) {
        movie.reset();
    }
    return good;

}

// return movie
bool MovieInventory::returnMovie(Movie *m, string & info)
{
    // if movie exists
    if (if_movie_exists(m)) {
        Movie* return_m = getMovie(m);
        return_m->increaseStock(1);
        info = return_m->getMovieInfo();
        return true;
    }
    return false;
}

// get movie by title
Movie* MovieInventory::getMovieByTitle(int indx, string title, int year)
{
    Movie* fd = nullptr;
    typeOfMovie[indx].getMovieByTitle(title, year, fd);
    return fd;
}

// add same movies
void MovieInventory::addAllSameM(Movie* m, int indx)
{
    Movie* fd = getMovieByTitle(indx, m->getTitle(), m->getYear());
    while (fd!=nullptr) {
        m->addDupMovies(fd);
        fd->addDupMovies(m);
        fd = getMovieByTitle(indx, m->getTitle(), m->getYear());
    }
}