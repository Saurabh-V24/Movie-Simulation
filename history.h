// ------------------------------------------------ history.h -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS343 Section D

// 03/13/2024

// Date of Last Modification

// --------------------------------------------------------------------------------------------------------------------

// Purpose - history.h is a header file that contains the class History. The class History is a subclass of Transaction.
//           The class History is used to display the Customer's transaction

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"
#include "customer.h"
#include "HashTable.h"
#include <iostream>
#include <string>

class History : public Transaction
{
public:
    History(int customerID);
    virtual ~History();

    virtual bool doTrans(Customer* customer);

private:
    int customerID;
};
#endif