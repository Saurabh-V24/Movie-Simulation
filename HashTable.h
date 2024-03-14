#ifndef CustomerInventory_hpp
#define CustomerInventory_hpp

#include <stdio.h>
#include "customer.h"
#include <iostream>

class CustomerInventory
{
public:
    static const int MAXN = 10000;
    
    CustomerInventory();
    ~CustomerInventory();
    
    Customer* getCustomer(int id);
    bool customerExisting(int id);
    bool addCustomer(int id, string first_name, string last_name);
    bool removeCustomer(int id);
private:
    struct customerNode
    {
        Customer* customer;
        customerNode* next;
    };
    // HASH TABLE
    customerNode* hash_T[MAXN];
    
    int hash_f(int id);
    void deleteRec(customerNode* c);
};

#endif /* CustomerInventory_hpp */
