#include <stdio.h>
#include "Drama.h"

Drama::Drama(char typeOfMovie, char media, string title, string director, int stock, int yearReleased):Movie(typeOfMovie, media, title, director, stock, yearReleased)
{
}

Drama::~Drama() {}

bool Drama::operator<(const Movie&other)const{
    if(director < other.getDirector()){
        return true;
    }
    else if(director == other.getDirector() && title < other.getTitle()){
        return true;
    }
    else{
        return false;
    }
}

bool Drama::operator>(const Movie&other)const{
    if(director > other.getDirector()){
        return true;
    }
    else if(director == other.getDirector() && title > other.getTitle()){
        return true;
    }
    else{
        return false;
    }
}

bool Drama::operator==(const Movie& other) const{
    if(director == other.getDirector() && title == other.getTitle()){
        return true;
    }
    else{
        return false;
    }
}
bool Drama::operator!=(const Movie& other)const{
    return !(*this == other);
}





