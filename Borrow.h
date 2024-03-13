#ifndef BORROW_H
#define BORROW_H
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"

class Customer;
class Movie;
class HashTable;

class Borrow : public Transaction
{
public:
    Borrow(Customer *customer, Movie *movie);
    virtual ~Borrow();
    virtual bool doTrans(HashTable*);
    virtual void setData();
    virtual string display();

private:
    Customer *customer;
    Movie *movie;
};
#endif
