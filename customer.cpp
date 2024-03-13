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


string Customer::getFullName() const
{
    return firstName + " " + lastName;
}


void Customer::getHistory() const
{
    cout << "History for " << getFullName() << endl;
    for (int i = 0; i < transactions.size(); i++)
    {
        cout << transactions[i]->display() << endl; 
    }
}

void Customer::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

