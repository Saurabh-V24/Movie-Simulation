#include <stdio.h>
#include "Comedy.h"
using namespace std;

Comedy::Comedy(char typeOfMovie, char media, string title, string director, int stock, int yearReleased) 
: Movie(typeOfMovie, media, title, director, stock, yearReleased){
}


Comedy::~Comedy()
{   
}

bool Comedy::operator==(const Movie& other) const{
    if(title == other.getTitle() && yearReleased == other.getReleaseYear()){
        return true;
    }
    else{
        return false;
    }
}

bool Comedy::operator<(const Movie& other)const{
    if(title < other.getTitle()){
        return true;
    }
    else if(title == other.getTitle() && yearReleased < other.getReleaseYear()){
        return true;
    }
    else{
        return false;
    }
}

bool Comedy::operator>(const Movie &other) const{
    if(title > other.getTitle()){
        return true;
    }
    else if(title == other.getTitle() && yearReleased > other.getReleaseYear()){
        return true;
    }
    else{
        return false;
    }
}

bool Comedy::operator!=(const Movie &other) const{
    return !(*this == other);
}







