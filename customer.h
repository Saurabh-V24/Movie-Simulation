#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

class Customer
{
private:
    string firstName;
    string lastName;
    int customerID;
    vector<Movie*> rentedMovies;
    // vector<Transaction*> transactions;

public:
    vector<Transaction*> transactions;
    Customer();
    ~Customer();
    Customer(int id, string lastName, string firstName);

    int getCustomerID() const;

    string getFirstName() const;

    string getLastName() const;
    
    string getFullName() const;

    void addMovie(Movie* movie);

    bool addTransaction(Transaction *type);

    // void addTransaction(string transaction);

    void getHistory() const;
};