#include <string>     // Add include statement for string
#include "customer.h" // Add include statement for customer.h
using namespace std;

Customer::Customer()
{
    customerID = 0;
    lastName = "";
    firstName = "";
}

Customer::~Customer() {}

Customer::Customer(int id, string lastName, string firstName)
{
    customerID = id;
    this->lastName = lastName;   // 'this' pointer to differentiate between parameter and member variable
    this->firstName = firstName; // 'this' pointer to differentiate between parameter and member variable
}

int Customer::getCustomerID() const // Add class scope
{
    return customerID;
}

string Customer::getFirstName() const
{
    return firstName;
}

string Customer::getLastName() const
{
    return lastName;
}

string Customer::getFullName() const
{
    return firstName + " " + lastName;
}

void Customer::addMovie(Movie *movie)
{
    rentedMovies.push_back(movie);
}

// void Customer::addTransaction(string transaction)
// {
//     switch (transaction[0])
//     {
//     case 'B':
//         transaction = "Borrowed " + transaction.substr(1);
//         break;
//     case 'R':
//         transaction = "Returned " + transaction.substr(1);
//         break;
//     }
//     transactions.push_back(transaction);
// }

bool Customer::addTransaction(Transaction *type)
{
    transactions.push_back(type);
    return true;
}

void Customer::getHistory() const
{
    cout << "History for " << getFullName() << endl;
    for (int i = 0; i < rentedMovies.size(); i++)
    {
        cout << rentedMovies[i]->getTitle() << " " << rentedMovies[i]->getReleaseYear() << endl;
    }
}