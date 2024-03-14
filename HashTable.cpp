// ------------------------------------------------ HashTable.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/10/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Hashtable to store customers, implemented using seperate chaining with nodes

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
#include "HashTable.h"

using namespace std;

// constructor
CustomerInventory::CustomerInventory()
{
    for (int i = 0; i < MAXN; i++)
    {
        hash_T[i] = new customerNode;
        hash_T[i]->customer = nullptr;
        hash_T[i]->next = nullptr;
    }
}

// destructor
CustomerInventory::~CustomerInventory()
{
    // clearing the hash table
    for (int i = 0; i < MAXN; i++)
    {
        deleteRec(hash_T[i]->next);
        delete hash_T[i]->customer;
        hash_T[i]->customer = nullptr;
        delete hash_T[i];
        hash_T[i] = nullptr;
    }
}

// get customer from table
Customer *CustomerInventory::getCustomer(int id)
{
    // bucket
    int b = hash_f(id);
    customerNode *c = hash_T[b]->next;
    // if no then no
    if (c == nullptr)
        return nullptr;
    // until we find
    while (c != nullptr)
    {
        if (c->customer->getID() == id)
            return c->customer;
        c = c->next;
    }
    return nullptr;
}

// check if such customer exists
bool CustomerInventory::customerExisting(int id)
{
    // bucket
    int b = hash_f(id);
    customerNode *c = hash_T[b]->next;
    if (c == nullptr)
        return false;
    while (c != nullptr)
    {
        if (c->customer->getID() == id)
            return true;
        c = c->next;
    }
    return false;
}

// add new customer
bool CustomerInventory::addCustomer(int id, string first_name, string last_name)
{
    // if customer already exists
    if (customerExisting(id))
        return false;

    // bucket
    int b = hash_f(id);
    customerNode *c = hash_T[b]->next;
    // add to first slot
    if (c == nullptr)
    {
        c = new customerNode;
        c->customer = new Customer(id, first_name, last_name);
        c->next = nullptr;
        hash_T[b]->next = c;
    }
    else
    {
        customerNode *t = new customerNode;
        t->customer = new Customer(id, first_name, last_name);
        t->next = c;
        hash_T[b]->next = t;
    }
    return true;
}

// delete helper
void CustomerInventory::deleteRec(customerNode *c)
{
    customerNode *to_del = c;
    while (c != nullptr)
    {
        c = c->next;
        delete to_del->customer;
        to_del->customer = nullptr;
        delete to_del;
        to_del = c;
    }
}

// hash function
int CustomerInventory::hash_f(int id)
{
    return id % MAXN;
}
