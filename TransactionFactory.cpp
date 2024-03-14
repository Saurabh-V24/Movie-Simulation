// ------------------------------------------------ TransactionFactory.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/12/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Implementation of transaction factory class, used to create transaction objects
//           Uses factory design pattern to create transaction objects
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#include "TransactionFactory.h"

TransactionFactory::TransactionFactory() {}

TransactionFactory::~TransactionFactory() {}

Transaction *TransactionFactory::create(char type, int id, Movie *&m)
{
    Transaction *transaction = nullptr;
    switch (type)
    {
    case 'B': // Borrow
        transaction = new Borrow(id, m);
        return transaction;
        break;
    case 'R': // Return
        transaction = new Return(id, m);
        return transaction;
        break;
    case 'I': // Inventory
        transaction = new Inventory;
        return transaction;
        break;
    case 'H': // History
        transaction = new History(id);
        return transaction;
        break;
    default:
        cout << "ERROR: " << type << " Invalid Transaction Type. Try Again." << endl;
        return transaction;
        break;
    }
}
