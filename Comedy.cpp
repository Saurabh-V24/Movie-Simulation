#include <stdio.h>
#include "Comedy.h"
using namespace std;

Comedy::Comedy()
{
    setTypeOfMovie('F');
}

Comedy::Comedy(int stock, string director, string title, int yearReleased)
{
    setTypeOfMovie('F');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(yearReleased);
}

Comedy::~Comedy()
{
    
}

void Comedy::buildingData(ifstream &file)
{
    struct MovieData {
        int stock;
        int releaseYear;
        string director;
        string title;
    } movieData;

    file.ignore(1);
    file >> movieData.stock;
    file.ignore(2);
    getline(file, movieData.director, ',');
    file.ignore(1);
    getline(file, movieData.title, ',');
    file >> movieData.releaseYear;

    setStock(movieData.stock);
    setDirector(movieData.director);
    setTitle(movieData.title);
    setReleaseYear(movieData.releaseYear);
}


bool Comedy::operator==(const Movie& other) const {
    return getStock() == other.getStock() && getDirector() == other.getDirector() 
    && getTitle() == other.getTitle() && getReleaseYear() == other.getReleaseYear();
}

bool Comedy::operator!=(const Movie& other)const
{
    return !(*this == other);
}

bool Comedy::operator>(const Movie& other) const{
    if(getTitle() > other.getTitle()){
        return true;
    }
    else if(getTitle() == other.getTitle() && getReleaseYear() > other.getReleaseYear()){
        return true;
    }
    return false;
}


bool Comedy::operator<(const Movie& other) const{
    if(getTitle() < other.getTitle()){
        return true;
    }
    else if(getTitle() == other.getTitle() && getReleaseYear() < other.getReleaseYear()){
        return true;
    }
    return false;
}


Movie* Comedy::operator=(const Movie &other){
    setStock(other.getStock());
    setDirector(other.getDirector());
    setTitle(other.getTitle());
    setReleaseYear(other.getReleaseYear());
    return this;
}

void Comedy::display(){
    cout << getTypeOfMovie() << " " << getStock() << " " << getDirector() << " " << getTitle() << " " << getReleaseYear() << endl;
}





