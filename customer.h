#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
private:
    string firstName;
    string lastName;
    int customerID;
    vector<Movie*> rentedMovies;
    vector<string> transactions;

public:
    Customer();
    ~Customer();
    Customer(int id, string lastName, string firstName);

    int getCustomerID() const;

    string getFirstName() const;

    string getLastName() const;
    
    string getFullName() const;

    void addMovie(Movie* movie);

    void addTransaction(string transaction);

    void getHistory() const;
};