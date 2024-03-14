#include "MovieInventory.h"
#include <iomanip>

using namespace std;

// constructor
MovieInventory::MovieInventory()
{
    BST comedy, classic, drama;
    movieType.push_back(comedy);
    movieType.push_back(classic);
    movieType.push_back(drama);
}

// destructor
MovieInventory::~MovieInventory()
{
    movieType.clear();
}

// get the movie from BST
Movie* MovieInventory::getMovie(Movie *m)
{
    Movie *fd = nullptr;
    switch (m->getGenre()) {
        case 'F': // Comedy
            movieType[0].getMovie(*m, fd);
            return fd;
            break;
        case 'D': // Drama
            movieType[1].getMovie(*m, fd);
            return fd;
            break;
        case 'C': // Classics
            movieType[2].getMovie(*m, fd);
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
    for (int i=0; i<movieType.size(); i++) {
        cout << "-----------------------" << endl;
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
        cout << movieType[i];
        movieType[i].reset();
    }
}

// add movie to the inventory
bool MovieInventory::addMovie(Movie *&m)
{
    bool good = false;
    if (m) {
        switch (m->getGenre()) {
            case 'F': // Comedy
                good = movieType[0].addMovie(m);
                return good;
                break;
                
            case 'C': // Classics
                good = movieType[2].addMovie(m);
                if (good) // insert pointers to the same movies with different actors
                {
                    m -> setC(true);
                    addAllSameM(m, 1);
                    movieType[2].reset();
                }
                return good;
                break;
                
            case 'D': // Drama
                good = movieType[1].addMovie(m);
                return good;
                break;
                
            default:
                return good;
                break;
        }
    }
    return good;
}
// borrow movie
bool MovieInventory::borrowMovie(Movie *m, string & info)
{
    bool good = false;
    // if movie exists
    if (if_movie_exists(m)) {
        Movie* borrow = getMovie(m);
        if (borrow->decreaseStock(1)) { // update stock
            info = borrow->getMovieInfo();  // get info
            good = true;
        }
    }
    for (int i=0; i<movieType.size(); i++) movieType[i].reset();
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
    movieType[indx].getMovieByTitle(title, year, fd);
    return fd;
}

// add same movies
void MovieInventory::addAllSameM(Movie* m, int indx)
{
    Movie* fd = getMovieByTitle(indx, m->getTitle(), m->getYear());
    while (fd!=nullptr) {
        m->addSameMovies(fd);
        fd->addSameMovies(m);
        fd = getMovieByTitle(indx, m->getTitle(), m->getYear());
    }
}