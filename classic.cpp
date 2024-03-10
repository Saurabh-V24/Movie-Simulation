
#include "classic.h"
using namespace std;


Classic::Classic()
{
    setTypeOfMovie('C');
}

Classic::Classic(int stock, string director, string title, string majorActor, int monthReleased, int yearReleased)
{
    setTypeOfMovie('C');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseMonth(monthReleased);
    setReleaseYear(yearReleased);
}

Classic::~Classic()
{
    
}

void Classic::buildingData(ifstream &file)
{
    struct MovieData {
        int stock;
        int releaseMonth;
        int releaseYear;
        string director;
        string title;
        string majorActor;
    } 
    movieData;

    string firstName;
    string lastName;

    file.ignore(1);
    file >> movieData.stock;
    file.ignore(2);
    getline(file, movieData.director, ',');
    getline(file, movieData.title, ',');
    file >> firstName >> lastName >> movieData.releaseMonth >> movieData.releaseYear;

    movieData.majorActor = firstName + " " + lastName;

    setStock(movieData.stock);
    setDirector(movieData.director);
    setTitle(movieData.title);
    setMajorActor(movieData.majorActor);
    setReleaseMonth(movieData.releaseMonth);
    setReleaseYear(movieData.releaseYear);
}


void Classic::setMajorActor(string majorActor)
{
    this->majorActor = majorActor;
}

string Classic::getMajorActor()const
{
    return this->majorActor;
}

bool Classic::setReleaseMonth(int month)
{
    if(month < 1)
    {
        return false;
    }
    
    this->releaseMonth = month;
    return true;
}

int Classic::getReleaseMonth()const
{
    return this->releaseMonth;
}

bool Classic::operator==(const Movie& other)const
{
    if(getStock() == other.getStock())
    {
        if(getDirector().compare(other.getDirector()) == 0)
        {
            if(getTitle().compare(other.getTitle()) == 0)
            {
                if(getReleaseMonth() == other.getReleaseMonth())
                {
                    if(getReleaseYear() == other.getReleaseYear())
                    {
                        if(getMajorActor().compare(other.getMajorActor()) == 0)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Classic::operator!=(const Movie& other)const
{
    return !(*this == other);
}

bool Classic::operator>(const Movie& other) const
{
    if (getReleaseYear() > other.getReleaseYear())
    {
        return true;
    }
    else if (getReleaseYear() == other.getReleaseYear())
    {
        
        if (getReleaseMonth() > other.getReleaseMonth())
        {
            
            return true;
        }
        else if (getReleaseMonth() == other.getReleaseMonth())
        {
            if (getMajorActor().compare(other.getMajorActor()) > 0)
            {
                return true;
            }
            else
            { 
                return false;
            }
        }
        else
        {  
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Classic::operator<(const Movie& other) const
{
    if (getReleaseYear() < other.getReleaseYear())
    {
        return true;
    }
    else if (getReleaseYear() == other.getReleaseYear())
    {
         
        if (getReleaseMonth() < other.getReleaseMonth())
        {
            return true;
        }
        else if (getReleaseMonth() == other.getReleaseMonth())
        {
            if (getMajorActor().compare(other.getMajorActor()) < 0)
            {
                return true;
            }
            else
            {
                return false;
            }
         }
        else{
            return false;
        }
    }
    else
    {
        return false;
    }
}

Movie* Classic::operator=(const Movie &c){
    setStock(c.getStock());
    setDirector(c.getDirector());
    setTitle(c.getTitle());
    setMajorActor(c.getMajorActor());
    setReleaseMonth(c.getReleaseMonth());
    setReleaseYear(c.getReleaseYear());

    return this;
}

void Classic::display(){
    cout << getTypeOfMovie() << " " << getStock() << " " << getDirector() << " " << getTitle()
    << " " << getMajorActor() << " " << getReleaseMonth() << " " << getReleaseYear() << endl;
}

