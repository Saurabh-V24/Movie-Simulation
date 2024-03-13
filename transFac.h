//---------------------------------------------------------------------------
// TransactionFactory.h
//---------------------------------------------------------------------------
// CSS 343 B
// Creation Date: 05/12/2023
//---------------------------------------------------------------------------
// This is the description of TransactionFactory class
//
//---------------------------------------------------------------------------
#ifndef TransactionFactory_hpp
#define TransactionFactory_hpp

#include "transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"
#include "Movie.h"
#include "HashTable.h"
#include "customer.h"
#include <sstream>

using namespace std;

class TransactionFactory
{
public:
    TransactionFactory();                              // constructor
    ~TransactionFactory();                             // destructor
    Transaction *create(char type, Customer *&id, Movie *&m); // create transactions
};

#endif /* TransactionFactory_h */
