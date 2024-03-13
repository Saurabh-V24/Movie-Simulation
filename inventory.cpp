#include "inventory.h"

Inventory::Inventory() {}

Inventory::~Inventory()
{
}

void Inventory::buildInventory(string const &movie)
{
    ifstream movies(movie);
    if (!movies)
    {
        cerr << "ERROR: Invalid" << endl;
        return;
    }
    while (!movies.eof())
    {

        char movieType;
        movies >> movieType;

        switch (movieType)
        {
            case 'C':
            {
                Classic *c = new Classic();
                c->buildingData(movies);
                classic.push_back(*c);
                break;
            }
            case 'F':
            {
                Comedy *f = new Comedy();
                f->buildingData(movies);
                comedy.push_back(*f);
                break;
            }
            case 'D':
            {
                Drama *d = new Drama();
                d->buildingData(movies);
                drama.push_back(*d);
                break;
            }
            default:{
                cerr << "ERROR: " << movieType << " Invalid Genre. Try Again. " << endl;
                movies.ignore(100, '\n');
                break;
            }
        }
    }
    movies.close();
}

void Inventory::viewingClassic()
{
    for (int i = 0; i < classic.size(); i++)
    {
        classic[i].display();
    }

    cout << endl;
}

void Inventory::viewingComedy()
{
    for (int i = 0; i < comedy.size(); i++)
    {
        comedy[i].display();
    }

    cout << endl;
}

void Inventory::viewingDrama()
{
    for (int i = 0; i < drama.size(); i++)
    {
        drama[i].display();
    }

    cout << endl;
}

void Inventory::viewingInventory()
{
    for(int i = 0; i < 95; i++)
    {
        cout<< "-";
    }
    cout<<endl;
    cout << "Movie Inventory" << endl;

    cout << " Comedies:" << endl;
    viewingComedy();

    cout << " Dramas:" << endl;
    viewingDrama();

    cout << " Classics:" << endl;
    viewingClassic();
    for(int i = 0; i < 95; i++)
    {
        cout<< "-";
    }
    cout<<endl;
}

bool Inventory::searchingClassic(int releaseMonth, int releaseYear, string majorActor, Movie *&movie)
{
    for (int i = 0; i < classic.size(); i++)
    {
        if (releaseMonth == classic[i].getReleaseMonth() && releaseYear == classic[i].getReleaseYear() && majorActor == classic[i].getMajorActor())
        {
            if (classic[i].getStock() == 0)
            {
                cerr << "ERROR: Movie not in stock " << endl;
                return false;
            }
            movie = &classic[i];
            return true;
        }
    }
    // cerr << "ERROR: Movie not found " << endl;
    return false;
}

bool Inventory::searchingComedy(string title, int releaseYear, Movie *&movie)
{
    for (int i = 0; i < comedy.size(); i++)
    {
        if (title == comedy[i].getTitle() && releaseYear == comedy[i].getReleaseYear())
        {
            if (comedy[i].getStock() == 0)
            {
                cerr << "ERROR: Movie out of stock" << endl;
                return false;
            }
            movie = &comedy[i];
            return true;
        }
    }
    // cerr << "ERROR: Movie is not found" << endl;
    return false;
}

bool Inventory::searchingDrama(string director, string title, Movie *&movie)
{
    for (int i = 0; i < drama.size(); i++)
    {
        if (director == drama[i].getDirector() && title == drama[i].getTitle())
        {
            if (drama[i].getStock() == 0)
            {
                cerr << "ERROR: Movie out of stock" << endl;
                return false;
            }
            movie = &drama[i];
            return true;
        }
    }
    // cerr << "ERROR: Movie is not found" << endl;
    return false;
}


// int main() {
//     // testing the inventory class
//     Inventory inventory;

//     // Replace "movies.txt" with the actual name of your movie file
//     inventory.buildInventory("data4movies.txt");
//     inventory.viewingInventory();

//     // // Display all Drama movies
//     // cout << "Drama Movies:" << endl;
//     // inventory.viewingDrama();

//     // // Display all Classic movies
//     // cout << "Classic Movies:" << endl;
//     // inventory.viewingClassic();

//     // // Display all Comedy movies
//     // cout << "Comedy Movies:" << endl;
//     // inventory.viewingComedy();

//     // Example of searching and displaying a Drama movie

//     return 0;
    
// }
