
#ifndef TransactionFactory_hpp
#define TransactionFactory_hpp

#include <stdio.h>
#include "transaction.h"
#include "inventory.h"
#include "movie.h"
#include <sstream>

using namespace std;

class TransactionFactory
{
public:
    TransactionFactory();               // constructor
    ~TransactionFactory();              // destructor
    Transaction* create(char type, int id, Movie*& m);   // create transactions
};


#endif /* TransactionFactory_h */
