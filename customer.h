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
    vector<Transaction *> transactions;

public:
    Customer();
    ~Customer();
    Customer(int id, string lastName, string firstName);

    int getCustomerID() const;

    string getFullName() const;

    void getHistory() const;

    void addTransaction(Transaction *);
};