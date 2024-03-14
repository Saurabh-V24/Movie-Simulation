#include "TransactionFactory.h"

TransactionFactory::TransactionFactory() {}

TransactionFactory::~TransactionFactory() {}

Transaction* TransactionFactory::create(char type, int id, Movie *&m)
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
