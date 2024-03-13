#ifndef Transaction_h
#define Transaction_h

#include <iostream>
#include <string>
#include "Movie.h"
#include "customer.h"
#include "HashTable.h";

using namespace std;
class Customer;
class Movie;
class HashTable;

class Transaction
{
public:
    // constructor
    Transaction();
    // destructor
    virtual ~Transaction();
    // does transaction
    virtual bool doTrans();
    // setting data will update the stock of the movie
    // and update the customer history
    virtual void setData();
    // displays entire transaction
    virtual string display();

private:
    // type of transaction
    char transType;
};
#endif