// ------------------------------------------------ business.h -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/13/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Header file for business, business file reads text files to populate data structures and execute commands

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#ifndef business_hpp
#define business_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
#include "HashTable.h"
#include "movie.h"
#include "MovieFactory.h"
#include "MovieInventory.h"
#include "transaction.h"
#include "TransactionFactory.h"

using namespace std;

class Business
{
public:
    Business();
    ~Business();
    
    void readCustomerFile (ifstream&);
    void readMovieFile (ifstream&);
    void readTransactionFile (ifstream&);
    bool performTransaction (Transaction*);

private:
    MovieInventory movieTree;                      // BST
    CustomerInventory customerHashTable;           // hash table
    MovieFactory movieFactory;                     // movie factory
    TransactionFactory transFactory;               // transaction factory
    
    string readStringStream(stringstream&);
};

#endif 
