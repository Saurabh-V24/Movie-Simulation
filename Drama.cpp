#include <stdio.h>
#include "Drama.h"

Drama::Drama()
{
    setTypeOfMovie('D');
}


Drama::Drama(int stock, string director, string title, int yearReleased)
{
    setTypeOfMovie('D');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(yearReleased);
}

Drama::~Drama() {}


void Drama::buildingData(ifstream &file)
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

bool Drama::operator==(const Movie& other) const {
    return (getStock() == other.getStock()) && (getDirector().compare(other.getDirector()) == 0) 
    && (getTitle().compare(other.getTitle()) == 0) && (getReleaseYear() == other.getReleaseYear());
}

bool Drama::operator!=(const Movie& other)const
{
    return !(*this == other);
}


bool Drama::operator>(const Movie& other) const {
    if (getDirector() != other.getDirector()) {
        return getDirector() > other.getDirector();
    }
    return getTitle() > other.getTitle();
}


bool Drama::operator<(const Movie& other) const{
    int directorComparison = getDirector().compare(other.getDirector());
    if (directorComparison < 0 || (directorComparison == 0 && getTitle().compare(other.getTitle()) < 0))
    {
        return true;
    }
    return false;
}

Movie* Drama::operator=(const Movie &d)
{
    setStock(d.getStock());
    setDirector(d.getDirector());
    setTitle(d.getTitle());
    setReleaseYear(d.getReleaseYear());
    return this;
}

void Drama::display()
{
    cout << getTypeOfMovie() << " " << getStock() << " " << getDirector() << " " << getTitle() << " " << getReleaseYear() << endl;
}
