#include "HashTable.h"

using namespace std;

// constructor
CustomerInventory::CustomerInventory()
{
    for (int i=0; i<MAXN; i++) {
        hash_T[i] = new customerNode;
        hash_T[i]->customer = nullptr;
        hash_T[i]->next = nullptr;
    }
}

// destructor
CustomerInventory::~CustomerInventory()
{
    // clearing the hash table
    for (int i=0; i<MAXN; i++) {
        deleteRec(hash_T[i]->next);
        delete hash_T[i]->customer;
        hash_T[i]->customer = nullptr;
        delete hash_T[i];
        hash_T[i]=nullptr;
    }
}

// get customer from table
Customer* CustomerInventory::getCustomer(int id)
{
    // bucket
    int b = hash_f(id);
    customerNode* c = hash_T[b]->next;
    // if no then no
    if (c==nullptr) return nullptr;
    // until we find
    while (c!=nullptr) {
        if (c->customer->getID() == id) return c->customer;
        c = c->next;
    }
    return nullptr;
}

// check if such customer exists
bool CustomerInventory::customerExisting(int id)
{
    // bucket
    int b = hash_f(id);
    customerNode* c = hash_T[b]->next;
    if (c==nullptr) return false;
    while (c!=nullptr) {
        if (c->customer->getID() == id) return true;
        c = c->next;
    }
    return false;
}

// add new customer
bool CustomerInventory::addCustomer(int id, string first_name, string last_name)
{
    // if customer already exists
    if (customerExisting(id)) return false;
    
    // bucket
    int b = hash_f(id);
    customerNode* c = hash_T[b]->next;
    // add to first slot
    if (c==nullptr) {
        c = new customerNode;
        c->customer = new Customer(id, first_name, last_name);
        c->next = nullptr;
        hash_T[b]->next = c;
    }
    else {
        customerNode* t = new customerNode;
        t->customer = new Customer(id, first_name, last_name);
        t->next = c;
        hash_T[b]->next = t;
    }
    return true;
}

// remove customer
// bool CustomerInventory::removeCustomer(int id)
// {
//     // if customer exists
//     if (customerExisting(id)) {
//         // bucket
//         int b = hash_f(id);
//         // current and previous
//         customerNode* cr = hash_T[b]->next;
//         customerNode* pr = hash_T[b];
//         // find and delete
//         while (cr!=nullptr) {
//             if (cr->customer->getID() == id) {
//                 pr->next = cr->next;
//                 // delete
//                 cr->next = nullptr;
//                 delete cr->customer;
//                 cr->customer = nullptr;
//                 delete cr;
//                 cr = nullptr;
//                 return true;
//             }
//             pr = cr;
//             cr = cr->next;
//         }
//     }
//     return false;
// }

// delete helper
void CustomerInventory::deleteRec(customerNode *c)
{
    customerNode* to_del = c;
    while (c!=nullptr) {
        c = c->next;
        delete to_del->customer;
        to_del->customer = nullptr;
        delete to_del;
        to_del = c;
    }
}

// hash function
int CustomerInventory::hash_f(int id) {
    return id%MAXN;
}

