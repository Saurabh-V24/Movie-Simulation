#include "Drama.h"
using namespace std;

Drama::Drama() : Movie(){ 
}

Drama::Drama(int stock, string director, string title, int yearReleased){
    setTypeOfMovie('D');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearReleased(yearReleased);
}

Drama::~Drama(){}

void Drama::buildingData(ifstream &file){
    Movie::buildingData(file);
}

bool Drama::operator==(const Movie& compareDrama) const {
    return (getStock() == compareDrama.getStock()) && (getDirector().compare(compareDrama.getDirector()) == 0) 
    && (getTitle().compare(compareDrama.getTitle()) == 0) && (getYearReleased() == compareDrama.getYearReleased());
}

bool Drama::operator!=(const Movie& compareDrama) const {
    return !(*this == compareDrama);
}

bool Drama::operator>(const Movie& compareDrama) const {
    if (getDirector() != compareDrama.getDirector()) {
        return getDirector() > compareDrama.getDirector();
    }
    return getTitle() > compareDrama.getTitle();
}


bool Drama::operator<(const Movie& compareDrama) const{
    int directorComparison = getDirector().compare(compareDrama.getDirector());
    if (directorComparison < 0 || (directorComparison == 0 && getTitle().compare(compareDrama.getTitle()) < 0))
    {
        return true;
    }
    return false;
}

Movie* Drama::operator=(const Movie &compareDrama){
    setStock(compareDrama.getStock());
    setDirector(compareDrama.getDirector());
    setTitle(compareDrama.getTitle());
    setYearReleased(compareDrama.getYearReleased());
    return this;
}


void Drama::display(){
    cout << getTypeOfMovie() << " " << getStock() << " " << getDirector() << " " << getTitle() << " " << getYearReleased() << endl;
}
