#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"

using namespace std;

class Customer
{
private:
    string firstName;
    string lastName;
    int customerID;
    vector<Movie> rentedMovies;
    vector<string> transactions;

public:

    Customer(int id, string lastName, string firstName);

    int getCustomerID() const
    {
        return customerID;
    }

    string getFirstName() const
    {
        return firstName;
    }

    string getLastName() const
    {
        return lastName;
    }

    string getFullName() const
    {
        return firstName + " " + lastName;
    }

    void addMovie(Movie* movie)
    {
        rentedMovies.push_back(movie);
    }

    void addTransaction(string transaction)
    {
        switch(transaction[0])
        {
            case 'B':
                transaction = "Borrowed " + transaction.substr(1);
                break;
            case 'R':
                transaction = "Returned " + transaction.substr(1);
                break;
        }
        transactions.push_back(transaction);
    }

    void getHistory() const
    {
        cout << "History for " << getFullName() << endl;
        for (int i = 0; i < rentedMovies.size(); i++)
        {
            cout << rentedMovies[i].getTitle() << " " << rentedMovies[i].getYearReleased() << endl;
        }
    }
};