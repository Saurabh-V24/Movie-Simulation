/**
 * Business
 * builds customers and inventory
 * process transactions
 */
#ifndef BUSINESS_H
#define BUSINESS_H

// #include "inventory.h"
#include "HashTable.h"
#include "customer.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Business
{
private:
    // Inventory inventory;
    HashTable customers;

public:
    Business();
    ~Business();

    void buildCustomer(const string &filename);
    Customer *getCustomer(int customerID);
};

#endif