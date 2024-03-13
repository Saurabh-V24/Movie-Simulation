/**
 * Business
 * builds customers and inventory
 * process transactions
 */
#ifndef BUSINESS_H
#define BUSINESS_H

#include "inventory.h"
#include "transaction.h"
#include "Movie.h"
#include "Drama.h"
#include "classic.h"
#include "Comedy.h"
#include "Borrow.h"
#include "Return.h"
#include "HashTable.h"
#include "transaction.h"
#include "customer.h"
#include "history.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Business
{
private:
    HashTable customers;
    Inventory movie;

public:
    Business();
    Business(string const &file);
    ~Business();

    void buildCustomer(const string &filename);
    void readCommands(const string &file);
};

#endif