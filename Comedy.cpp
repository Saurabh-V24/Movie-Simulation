#include "Comedy.h"
#include <iostream>
using namespace std;

Comedy::Comedy() : Movie(){ 
    setTypeOfMovie('F');
    setStock(0);
    setDirector("");
    setTitle("");
    setYearReleased(0);
}

Comedy::Comedy(int stock, string director, string title, int yearReleased){
    setTypeOfMovie('F');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearReleased(yearReleased);
}

Comedy::~Comedy(){
}

void Comedy::buildingData(ifstream &file)
{
    int stock;
    int yearReleased;
    string director; 
    string title;
    
    file.ignore(1);
    file >> stock;
    file.ignore(2);
    getline(file, director, ',');
    file.ignore(1);
    getline(file, title, ',');
    file >> yearReleased;
    
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearReleased(yearReleased);
}

bool Comedy::operator==(const Movie& f) const {
    return getStock() == f.getStock() && getDirector() == f.getDirector() 
    && getTitle() == f.getTitle() && getYearReleased() == f.getYearReleased();
}

bool Comedy::operator!=(const Movie& f)const {
    return !(*this == f);
}

bool Comedy::operator>(const Movie& f) const{
    if(getTitle() > f.getTitle()){
        return true;
    }
    else if(getTitle() == f.getTitle() && getYearReleased() > f.getYearReleased()){
        return true;
    }
    return false;
}

bool Comedy::operator<(const Movie& f) const{
    if(getTitle() < f.getTitle()){
        return true;
    }
    else if(getTitle() == f.getTitle() && getYearReleased() < f.getYearReleased()){
        return true;
    }
    return false;
}

void Comedy::display(){
    cout << getTypeOfMovie() << " " << getStock() << " " << getDirector() << " " << getTitle() << " " << getYearReleased() << endl;
}

Movie* Comedy::operator=(const Movie &f){
    setStock(f.getStock());
    setDirector(f.getDirector());
    setTitle(f.getTitle());
    setYearReleased(f.getYearReleased());
    return this;
}





