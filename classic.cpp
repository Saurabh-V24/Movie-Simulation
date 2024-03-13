
#include "classic.h"
using namespace std;


Classic::Classic(char typeOfMovie, char media, string title, string director, int stock, int year, int month, string majorActor):Movie(typeOfMovie, media, title, director, stock, yearReleased) 
{
    this->majorActor = majorActor;
    this->month = month;
}

Classic::~Classic(){
}

int Classic::getReleaseMonth() const{
    return this->month;
}

string Classic::getMajorActor() const{
    return this-> majorActor;
}

bool Classic::operator==(const Movie& other) const{
    if(month == other.getReleaseMonth() && yearReleased == other.getReleaseYear() && getMajorActor() == other.getMajorActor()){
        return true;
    }
    else{
        return false;
    }
}

int Classic::getDupStock() const{
    int dupStock = getStock();
    for(int i = 0; i<dupMovies.size(); i++){
        if(!dupMovies[i] -> statusOfClassicMovie()){
            dupStock += dupMovies[i]->getStock();
            dupMovies[i]->manageClassicStock(true);             
        }
    }
    return dupStock;
}

bool Classic::decreaseStock(int other){
    if(stock >= other && other > 0){
        stock-=other;
        return true;
    }
    else if(dupMovies.size() > 0){
        manageClassicStock(true);
        for(int i =0; i < dupMovies.size(); i++){
            if(!dupMovies[i] -> statusOfClassicMovie() && dupMovies[i] -> decreaseStock(other)) return true;
            dupMovies[i] -> manageClassicStock(true);
        }
        return false;
    }
    else{
        return false;
    }
}

void Classic::addDupMovies(Movie*& other){
    dupMovies.push_back(other);
}


bool Classic::operator!=(const Movie &other)const{
    return !(*this == other);
}

bool Classic::operator>(const Movie &other)const{
    if(yearReleased > other.getReleaseYear()){
        return true;
    }
    else if(yearReleased ==other.getReleaseYear()){
        if(month > other.getReleaseMonth()){
            return true;
        }
        else if(month == other.getReleaseMonth() && majorActor > other.getMajorActor()){
            return true;
        }
    }
    return false;
}

bool Classic::operator<(const Movie&other )const{
    if(yearReleased < other.getReleaseYear()){
        return true;
    }
    else if(yearReleased == other.getReleaseYear()){
        if(month < other.getReleaseMonth()){
            return true;
        }
        else if (month == other.getReleaseMonth() && majorActor < other.getMajorActor()){
            return true;
        }

    }
    return false;
}


void Classic::display(){
    cout << setw(5) << getTypeOfMovie() << setw(5) << getMedia() << setw(5) << getTitle() << setw(5)
    << getDirector() << setw(5) << getReleaseMonth() << setw(5) << getReleaseYear << setw(5) << getDupStock() << endl;

    cout << setw(60) << this->getMajorActor() << "--------------------" << setw(4) << this->getStock() << endl;

    for(int i = 0; i< dupMovies.size(); i++){
        cout << setw(60) << dupMovies[i]->getMajorActor() <<"--------------------" << setw(4) << dupMovies[i] -> getStock() << endl;

    }
}

