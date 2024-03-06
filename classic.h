#ifndef Classic_h
#define Classic_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
public:
    Classic();
    Classic(int stock, string director, string title, string majorActor,int monthReleased, int yearReleased);
    ~Classic();
    
    void buildingData(ifstream &file);
    void setMajorActor(string majorActor);
    bool setReleaseMonth(int month);
    
    string getMajorActor()const;
    int getReleaseMonth()const;
    
    void display();
    bool operator==(const Movie& ) const;
    bool operator!=(const Movie& ) const;
    bool operator>(const Movie& ) const;
    bool operator<(const Movie& ) const;
    Movie* operator=(const Movie& );
    
private:
    string majorActor;
    int releaseMonth;
    
};

#endif 