#include "classic.h"
using namespace std;

Classic::Classic() : Movie(){ 
}

Classic::Classic(char genre, int stock, string director, string title, string majorActor, int month, int yearReleased)
{
    setTypeOfMovie(genre);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseMonth(month);
    setYearReleased(yearReleased);
}

Classic::~Classic() {}

void Classic::display()
{
    // display the movie from genre, media, title, director, major actor, release month, and year released
    cout << getTypeOfMovie() << " "
         << "D"
         << " " << getStock() << " " << getDirector() << " " << getTitle() << " " << getMajorActor() << " " << getReleaseMonth() << " " << getYearReleased() << endl;
}
/**
 * operator== - compares if two classic movies are the same
 * precondition: none
 * postcondition: returns true if the classic movies are the same, false otherwise
 */
bool Classic::operator==(const Movie &other) const
{
    // compare the classic movies
    if (getTypeOfMovie() == 'D' && getReleaseMonth() == other.getReleaseMonth() && getYearReleased() == other.getYearReleased() && getMajorActor() == other.getMajorActor())
    {
        return true;
    }
    return false;
}
// end of operator==

/**
 * operator!= - compares if two classic movies are not the same
 * precondition: none
 * postcondition: returns true if the classic movies are not the same, false otherwise
 */
bool Classic::operator!=(const Movie &other) const
{
    // compare the classic movies
    if (getTypeOfMovie() == 'D' && getReleaseMonth() == other.getReleaseMonth() && getYearReleased() == other.getYearReleased() && getMajorActor() == other.getMajorActor())
    {
        return false;
    }
    return true;
}
// end of operator!=

/**
 * operator> - compares if one classic movie is greater than the other
 * precondition: none
 * postcondition: returns true if the classic movie is greater than the other, false otherwise
 * comparison rules: release date is the first priority then major actor, if the release date is the same, then compare the major actor
 * earlier release date is greater than the later release date
 * first name of major actor is greater than the second name of major actor
 * ex. Cary Grant is greater than Judy Garland
 */
bool Classic::operator>(const Movie &other) const
{
    // compare the classic movies
    if (getYearReleased() < other.getYearReleased())
    {
        return true;
    }
    // if year equal, compare month
    else if (getYearReleased() == other.getYearReleased())
    {
        if (getReleaseMonth() < other.getReleaseMonth())
        {
            return true;
        }
        // if month equal, compare major actor
        else if (getReleaseMonth() == other.getReleaseMonth())
        {
            // compare first substring of major actor
            if (getMajorActor() > other.getMajorActor())
            {
                return true;
            }
        }
    }
    return false;
}
// end of operator>

/**
 * operator< - compares if one classic movie is less than the other
 * precondition: none
 * postcondition: returns true if the classic movie is les the other, false otherwise
 * if the substring of the major actor is less than the other, then return true
 */
bool Classic::operator<(const Movie &other) const
{
    // compare the classic movies
    if (getYearReleased() > other.getYearReleased())
    {
        return true;
    }
    // if equal then compare month
    else if (getYearReleased() == other.getYearReleased())
    {
        if (getReleaseMonth() > other.getReleaseMonth())
        {
            return true;
        }
        // if month equal, then compare major actor
        else if (getReleaseMonth() == other.getReleaseMonth())
        {
            if (getMajorActor() < other.getMajorActor())
            {
                return true;
            }
        }
    }
    return false;
}
// end of operator<

/**
 * operator= - assigns the classic movie to another classic movie
 * precondition: none
 * postcondition: assigns the classic movie to another classic movie
 */
Movie *Classic::operator=(const Movie &other)
{
    // assign the classic movie to another classic movie
    setTypeOfMovie(other.getTypeOfMovie());
    setStock(other.getStock());
    setDirector(other.getDirector());
    setTitle(other.getTitle());
    setYearReleased(other.getYearReleased());
    setMajorActor(other.getMajorActor());
    setReleaseMonth(other.getReleaseMonth());
    return this;
}
// end of operator=
