#include "inventory.h"
#include <string>
using namespace std;

Inventory::Inventory(){}

Inventory::~Inventory(){}

void Inventory::creatingInventory(string const &movie){

    ifstream movies(movie);

    if(!movies){
        cerr << "ERROR: Invalid. Try again" << endl; 
        return;
    }

    char typeOfMovie;
    while(!movies.eof()){

        movies >> typeOfMovie;
        if(typeOfMovie == 'C'){
            Classic *c = new Classic();
            c->buildingData(movies);
            classicMovie.push_back(*c);
        }

        else if(typeOfMovie == 'D'){
            Drama *d = new Drama();
            d->buildingData(movies);
            dramaMovie.push_back(*d);
        }

        else if(typeOfMovie == 'F'){
            Comedy *f = new Comedy();
            f->buildingData(movies);
            comedyMovie.push_back(*f);
        }
        
        else{
            cerr << "ERROR: " << typeOfMovie << " Invalid Genre " << endl;
        }
    }
    movies.close();
}

void Inventory::viewingDrama(){
    for(int i = 0; i < dramaMovie.size(); i++){
        dramaMovie[i].display();
    }
    cout << endl;
}

void Inventory::viewingClassic(){
    for(int i = 0; i < classicMovie.size(); i++){
        classicMovie[i].display();
    }
    cout << endl;
}

void Inventory::viewingComedy(){
    for(int i = 0; i < comedyMovie.size(); i++){
        comedyMovie[i].display();
    }
    cout << endl;
}

bool Inventory::searchingDramaMovie(string director, string title, Movie *&movieSelection){
    for (int i = 0; i < dramaMovie.size(); i++){
        if (director == dramaMovie[i].getDirector() && title == dramaMovie[i].getTitle()){
            if (dramaMovie[i].getStock() == 0){
                cerr << "ERROR: Movie is out of stock" << endl;
                return false;
            }
            movieSelection = &dramaMovie[i];
            return true;
        }
    }
    cerr << "ERROR: Movie is not found" << endl;
    return false;
}


bool Inventory::searchingComedyMovie(string title, int releaseYear, Movie *&movieSelection){
    for (int i = 0; i < comedyMovie.size(); i++){
        if (title == comedyMovie[i].getTitle() && releaseYear == comedyMovie[i].getYearReleased()){
            if (comedyMovie[i].getStock() == 0){
                cerr << "ERROR: Movie is not in stock" << endl;
                return false;
            }
            movieSelection = &comedyMovie[i];
            return true;
        }
    }
    cerr << "ERROR: Movie is not found" << endl;
    return false;
}

bool Inventory::searchingClassicMovie(int releaseMonth, int releaseYear, string majorActor, Movie *&movieSelection){
    for (int i = 0; i < classicMovie.size(); i++){
        if (releaseMonth == classicMovie[i].getReleaseMonth() && 
        releaseYear == classicMovie[i].getYearReleased() && majorActor == classicMovie[i].getMajorActor()){
                if (classicMovie[i].getStock() == 0){
                    cerr << "ERROR: Movie is not in stock" << endl;
                    return false;
                }
                movieSelection = &classicMovie[i];
                return true;
        }
    }
    cerr << "ERROR: Movie is not found" << endl;
    return false;
}

int main() {
    // testing the inventory class
    Inventory i;
    cout << "Creating inventory" << endl;
    i.creatingInventory("data4movies.txt");
    cout << "Viewing Drama" << endl;
    i.viewingDrama();
    cout << "Viewing Classic" << endl;
    i.viewingClassic();
    cout << "Viewing Comedy" << endl;
    i.viewingComedy();
    return 0;
}