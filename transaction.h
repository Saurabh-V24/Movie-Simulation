#ifndef Transaction_h
#define Transaction_h

#include <iostream>
#include <string>
#include "Movie.h"

using namespace std;

class Transaction
{
public:
    Transaction();
    Transaction(char typeOfTransaction, int customerID, Movie *movie);
    ~Transaction();
    
    virtual void setCustomerID(int customerID);
    virtual void setTypeOfTransaction(char transactionType);
    virtual void setMovie(Movie *movie);

    virtual int getCustomerID()const;
    virtual char getTransactionType()const;
    virtual Movie* getMovie()const;
    
    virtual void doTrans(); 
    virtual void display()const; 
    
protected:
    int customerID;
    char typeOfTransaction;
    Movie *movie;
};

#endif