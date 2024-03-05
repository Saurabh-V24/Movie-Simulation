#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie() : typeOfMovie(' '), stock(0), director(""), title(""), yearReleased(0) {}

Movie::Movie(char typeOfMovie, int stock, string director, string title, int yearReleased)
{
    setTypeOfMovie(typeOfMovie);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearReleased(yearReleased);
}

Movie::~Movie() {}

CommittingMovie
void Movie::buildingData(ifstream& file) {

void Movie::buildingData(ifstream &file)
{

    int stock;
    int yearReleased;
    string director;
    string title;
CommittingMovie
    



    file.ignore(1);
    file >> stock;
    file.ignore(2);
    getline(file, director, ',');
    file.ignore(1);
    getline(file, title, ',');
    file >> yearReleased;
    CommittingMovie
    


    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearReleased(yearReleased);
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

void Movie::setYearReleased(int yearReleased)
{
    this->yearReleased = yearReleased;
}

void Movie::setMajorActor(string majorActor)
{
}

void Movie::setReleaseMonth(int month)
{
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

int Movie::getYearReleased() const
{
    return yearReleased;
}

string Movie::getMajorActor() const
{
    return majorActor;
}

int Movie::getReleaseMonth() const
{
    return month;
}

bool Movie::increaseStock()
{
    stock++;
    return true;
}

bool Movie::decreaseStock()
{
    if (stock == 0)
    {
        return false;
    }
    stock--;
    return true;
}

void Movie::display() const
{
    cout << getTypeOfMovie() << " " << getStock() << " " << getDirector() << " " << getTitle() << " " << getYearReleased() << endl;
}


// Movie* Movie::operator=(const Movie &c){

// Movie *Movie::operator=(const Movie &c)
// {

//     return this;
// }

int main()
{

    cout << "Part 1" << endl;
    ifstream infile1("data4movies.txt");
    if (!infile1)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // for each graph, find the shortest path from every node to all other nodes
    for (;;)
    {

        if (infile1.eof())
        {
            cout << "No more movies" << endl;
            break;
        }

        Movie movie;
        movie.buildingData(infile1);
        movie.display();

        cout << "Stock: " << movie.getStock() << endl;
        cout << "Director: " << movie.getDirector() << endl;
        cout << "Title: " << movie.getTitle() << endl;
        cout << "Year Released: " << movie.getYearReleased() << endl;
    }

}

    infile1.close();
}

