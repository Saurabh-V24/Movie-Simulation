// ------------------------------------------------ transaction.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/12/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Header file of transaction class, used to perform transactions and set data members
//           History, Borrow, Return, Inventory classes are derived from Transaction class
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#ifndef transaction_h
#define transaction_h

#include <stdio.h>

#include "HashTable.h"
#include "movie.h"
#include "MovieInventory.h"
using namespace std;

class Transaction
{
public:
    Transaction();
    virtual ~Transaction();
    virtual bool perform(MovieInventory &, CustomerInventory &);

private:
    char t_type;
};

class Borrow : public Transaction
{
public:
    Borrow(int, Movie *);
    virtual ~Borrow();
    virtual bool perform(MovieInventory &, CustomerInventory &);

private:
    Movie *movie;
    int ID;
};

class Return : public Transaction
{
public:
    Return(int, Movie *);                                        // constructor
    virtual ~Return();                                           // destructor
    int getCustomerID();                                         // get ID of the customer of the transaction
    virtual bool perform(MovieInventory &, CustomerInventory &); // perform Return movie

private:
    Movie *movie; // movie to Return
    int ID;       // customer responsible for the transaction
};

class History : public Transaction
{
public:
    History(int);       // constructor
    virtual ~History(); // destructor

    // history
    virtual bool perform(MovieInventory &, CustomerInventory &);

private:
    int ID; // customer responsible for the transaction
};

class Inventory : public Transaction
{
public:
    Inventory();
    virtual ~Inventory();
    virtual bool perform(MovieInventory &, CustomerInventory &);
};

#endif /* transaction_h */
