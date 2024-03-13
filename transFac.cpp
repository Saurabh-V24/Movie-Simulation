//---------------------------------------------------------------------------
// TransactionFactory.cpp
//---------------------------------------------------------------------------
// CSS 343 B
// Creation Date: 05/12/2023
//---------------------------------------------------------------------------
// This is the implementation of TransactionFactory class
//
//---------------------------------------------------------------------------
#include "transFac.h"

TransactionFactory::TransactionFactory() {}

TransactionFactory::~TransactionFactory() {}


Transaction* TransactionFactory::create(char type, Customer *&id, Movie *&m)
{
    Transaction* transaction = nullptr;
    switch(type)
    {
        case 'B': // Borrow
            transaction = new Borrow(id, m);
            return transaction;
            break;
        case 'R': // Return
            transaction = new Return(id, m);
            return transaction;
            break;
            // displays entire inventory
        // case 'I': // Inventory
        //     transaction = new Inventory;
        //     return transaction;
        //     break;
        case 'H': // History
            transaction = new History(id->getCustomerID());
            return transaction;
            break;
        default:
            cout << "ERROR: " << type << " Invalid Transaction Type. Try Again." << endl;
            return transaction;
            break;
    }
}
