// ------------------------------------------------ TransactionFactory.h -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/12/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Header file for transaction factory class, used to create transaction objects
//           Uses factory design pattern to create transaction objects
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
#ifndef TransactionFactory_hpp
#define TransactionFactory_hpp

#include <stdio.h>
#include "transaction.h"
#include "movie.h"
#include <sstream>

using namespace std;

class TransactionFactory
{
public:
    TransactionFactory();                              // constructor
    ~TransactionFactory();                             // destructor
    Transaction *create(char type, int id, Movie *&m); // create transactions
};

#endif /* TransactionFactory_h */
