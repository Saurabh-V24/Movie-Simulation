#include "inventory.h"
#include <iomanip>

Inventory::Inventory() {
    MovieBST Comedy;
    MovieBST Classic;
    MovieBST Drama;
    typeOfMovie.push_back(Comedy);
    typeOfMovie.push_back(Classic);
    typeOfMovie.push_back(Drama);
}

Inventory::~Inventory()
{
    typeOfMovie.clear();
}

Movie* Inventory::getMovie(Movie* movie){
    Movie *moviePtr = nullptr;
    switch(movie->getTypeOfMovie()){
        case 'F':
            typeOfMovie[0].gettingMovie(*movie, moviePtr);
            return moviePtr;
            break;
        case 'D':
            typeOfMovie[1].gettingMovie(*movie, moviePtr);
            return moviePtr;
            break;
        case 'C':
            typeOfMovie[2].gettingMovie(*movie, moviePtr);
            return moviePtr;
            break;
        default:
            moviePtr = nullptr;
            break;
    }
    return moviePtr;
}

bool Inventory::doesMovieExist(Movie *movie){
    Movie* moviePtr = getMovie(movie);
    if(moviePtr !=nullptr){
        return true;
    }
    else{
        return false;
    }  
}

void Inventory::viewInventory(){
    for(int i = 0; i < typeOfMovie.size(); i++){
        cout << "-----------------------" << endl;

        switch(i){
            case 0:
                cout << "Comedies: " << endl;
                cout << endl;
                cout<< setw(5) << "Genre" << setw(5) << "Media"  << setw(5) << "Title" << setw(5) << "Director" << setw(5) << "Year"
                << setw(5) << "Stock" << endl;
                break;
            case 1:
                cout << "Dramas: " << endl;
                cout << endl;
                cout<< setw(5) << "Genre" << setw(5) << "Media"  << setw(5) << "Title" << setw(5) << "Director" << setw(5) << "Year"
                << setw(5) << "Stock" << endl;
                break;
            case 2:
                cout << "Classic: " << endl;
                cout << endl;
                cout<< setw(5) << "Genre" << setw(5) << "Media"  << setw(5) << "Title" << setw(5) << "Director" << setw(5) << "Month"
                << setw(5) << "Year" << setw(5) << "Stock" << endl;
            default:
                break;
        }
        cout << typeOfMovie[i];
        typeOfMovie[i].reset();
    }
}

bool Inventory::addingMovie(Movie *&movie){
    bool isAdded = false;
    if(movie){
        switch(movie->getTypeOfMovie()){
            case 'F':
                isAdded = typeOfMovie[0].addMovie(movie);
                return isAdded;
                break;
            case 'D':
                isAdded = typeOfMovie[1].addMovie(movie);
                return isAdded;
                break;
            case 'C':
                isAdded = typeOfMovie[2].addMovie(movie);
                if(isAdded){
                    movie->manageClassicStock(true);
                    combineMovie(movie, 1);
                    typeOfMovie[2].reset();
                    
                }
                return isAdded;
                break;
            default:
                return isAdded;
                break;  

        }
    }
    return isAdded;

}

Movie* Inventory::getMovieByTitle(int position, string title, int year){
    Movie* moviePtr = nullptr;
    typeOfMovie[position].movieTitle(title, year, moviePtr);
    return moviePtr;
}

void Inventory::combineMovie(Movie* movie, int position){
    Movie *moviePtr = getMovieByTitle(position, movie->getTitle(), movie->getReleaseYear());
    while(moviePtr!= nullptr){
        movie->duplicateMovies(moviePtr);
        moviePtr->duplicateMovies(movie);
        moviePtr = getMovieByTitle(position, movie->getTitle(),movie->getReleaseYear());
    }
    
}


// int main() {
//     // testing the inventory class
//     Inventory inventory;

//     // Replace "movies.txt" with the actual name of your movie file
//     inventory.buildInventory("data4movies.txt");
//     inventory.viewingInventory();

//     // // Display all Drama movies
//     // cout << "Drama Movies:" << endl;
//     // inventory.viewingDrama();

//     // // Display all Classic movies
//     // cout << "Classic Movies:" << endl;
//     // inventory.viewingClassic();

//     // // Display all Comedy movies
//     // cout << "Comedy Movies:" << endl;
//     // inventory.viewingComedy();

//     // Example of searching and displaying a Drama movie

//     return 0;
    
// }
