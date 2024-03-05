#include <string>
#include <iostream>
#include <fstream>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
public:
    Classic(char genre, int stock, string director, string title, string majorActor, int month, int yearReleased);
    ~Classic();
    void display();

    string getMajorActor() const;
    int getReleaseMonth() const;
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<(const Movie &) const;
    Movie *operator=(const Movie &);

private:
    string majorActor;
    int releaseMonth;
};
