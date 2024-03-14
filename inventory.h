#ifndef inventory_h
#define inventory_h

#include <stdio.h>
#include "transaction.h"

using namespace std;

class Inventory : public Transaction
{
public:
    Inventory();
    virtual ~Inventory();
    virtual bool perform(MovieInventory&, HashTable&);
};

#endif /* inventory_h */
