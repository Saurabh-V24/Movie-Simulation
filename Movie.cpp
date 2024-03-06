#include "Movie.h"

Movie::Movie()
{
    setTypeOfMovie('B');
}

Movie::Movie(char movieType, int stock, string director, string title, int yearReleased)
{
    setTypeOfMovie(movieType);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(yearReleased);
}

Movie::~Movie(){}


void Movie::buildingData(ifstream &file)
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



void Movie::setTypeOfMovie(char typeOfMovie)
{
    this->typeOfMovie = typeOfMovie;
}


void Movie::setStock(int stock)
{
    this->stock = stock;
}

void Movie::setDirector(string director)
{
    this->director = director;
}


void Movie::setTitle(string title)
{
    this->title = title;
}


void Movie::setReleaseYear(int yearReleased)
{
    this->yearReleased = yearReleased;
}

void Movie::setMajorActor(string majorActor){}


bool Movie::setReleaseMonth(int month)
{
    if(month < 1)
    {
        return false;
    }
    
    return true;
}


char Movie::getTypeOfMovie() const
{
    return typeOfMovie;
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


int Movie::getReleaseYear( )const
{
    return yearReleased;
}


string Movie::getMajorActor()const
{
    return "";
}


int Movie::getReleaseMonth()const
{
    return 0;
}


bool Movie::increaseStock()
{
    stock++;
    return true;
}


bool Movie::decreaseStock()
{
    if(stock == 0)
    {
        return false;
    }
    
    stock--;
    return true;
}


Movie* Movie::operator=(const Movie &c)
{
    return this;
}

void Movie::display()const
{
    cout << getTypeOfMovie() << " " << getStock() << " " << getDirector() << " " << getTitle() << " " << getReleaseYear() << endl;
}
