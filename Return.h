#ifndef RETURN_H
#define RETURN_H
#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
using namespace std;

class Return : public Transaction
{
public:
    Return(Customer *customerID, Movie *movie);
    virtual ~Return();

    // overrides transaction doTrans
    virtual bool doTrans(HashTable *customerTable);
    // overrides transaction setData
    virtual void setData();
    // displays the transaction type and the movie info
    virtual string display();

private:
    Customer* customer;
    Movie *movie;
};
#endif