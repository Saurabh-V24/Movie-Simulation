#include "Movie.h"

Movie::Movie()
{
}

Movie::Movie(char typeOfMovie, char media, string title, string director, int stock, int yearReleased)
{
   this->typeOfMovie = typeOfMovie;
   this->media = media;
   this->title = title;
   this->director = director;
   this->stock = stock;
   this->yearReleased = yearReleased;
   this->preventDouble = false;
}

Movie::~Movie(){}

string Movie::infoOfMovie(string titleAndDirector)const
{
    titleAndDirector = title + " by " + director;
    return titleAndDirector;
}

char Movie::getTypeOfMovie() const
{
    return typeOfMovie;
}
char Movie::getMedia() const
{
    return media;
}

int Movie::getStock() const
{
    return stock;
}

string Movie::getDirector() const
{
    return director;
}

string Movie::getTitle() const
{
    return title;
}

int Movie::getReleaseYear() const
{
    return yearReleased;
}

string Movie::getMajorActor() const
{
    return "";
}

int Movie::getReleaseMonth() const
{
    return 0;
}

bool Movie::increaseStock(int other)
{
    stock += other;
    return true;
}

bool Movie::decreaseStock(int other)
{
    if(stock > 0 && stock >= other)
    {
        stock-=other;
        return true;
    }
    else
    {
        return false;
    }
}

void Movie::manageClassicStock(bool stockCount){
    preventDouble = stockCount;
}

bool Movie::statusOfClassicMovie() const{
    return preventDouble;
}

void Movie::duplicateMovies(Movie *& other){

}

bool Movie::operator==(const Movie& other){
    if(this -> title == other.title && this->yearReleased == other.getReleaseYear()){
        return true;
    }
    else{
        return false; 
    }
}

bool Movie::operator!=(const Movie& other){
    return !(*this == other);
}

bool Movie::operator<(const Movie& other){
    return this->yearReleased < other.getReleaseYear();
}
bool Movie::operator>(const Movie& other){
    return this->yearReleased > other.getReleaseYear();
}

void Movie::display() const
{
    cout << setw(5) << getTypeOfMovie() << setw(5) << getMedia() << setw(5) << getTitle() 
    << setw(5) << getDirector() << setw(5) << getReleaseYear() << setw(5) << getStock() <<endl;
}
