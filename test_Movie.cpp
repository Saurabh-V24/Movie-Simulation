using namespace std;
#include "movie.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{

    Movie movie;

    // Open the input file
    ifstream inputFile("data4movies.txt");
    if (!inputFile)
    {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    // Call the buildingData method to read data from the file
    movie.buildingData(inputFile);

    movie.display();
    // Close the input file
    inputFile.close();

    // Print the movie details
    cout << "Stock: " << movie.getStock() << endl;
    cout << "Director: " << movie.getDirector() << endl;
    cout << "Title: " << movie.getTitle() << endl;
    cout << "Year Released: " << movie.getYearReleased() << endl;

    // Additional checks for different movie types
    if (movie.getTypeOfMovie() == 'C')
    {
        cout << "Major Actor: " << movie.getMajorActor() << endl;
        cout << "Release Month: " << movie.getReleaseMonth() << endl;
    }
    else if (movie.getTypeOfMovie() == 'F' || movie.getTypeOfMovie() == 'D')
    {
        // No additional checks for 'F' or 'D' type movies
    }
    else
    {
        cerr << "Invalid Genre." << endl;
    }

    return 0;
}