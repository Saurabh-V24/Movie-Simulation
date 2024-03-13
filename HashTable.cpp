#include "HashTable.h"
#include "customer.h"

const int HASH_SIZE = 100;

int HashTable::hashFunction(const string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash = (hash * 23 + c) % HASH_SIZE;
    }
    return hash;
}

HashTable::HashTable()
{
    customerTable.fill(nullptr);
}

HashTable::~HashTable()
{
    for (Customer *customer : customerTable)
    {
        if (customer != nullptr) // Check if the pointer is not null before deleting
        {
            delete customer;
        }
    }
}

void HashTable::insert(const Customer &customer)
{
    int index = hashFunction(to_string(customer.getCustomerID()));
    while (customerTable[index] != nullptr)
    {
        index = (index + 1) % HASH_SIZE;
    }
    customerTable[index] = new Customer(customer);
}

Customer *HashTable::search(const string &customerID)
{
    int index = hashFunction(customerID);
    while (customerTable[index] != nullptr)
    {
        if (to_string(customerTable[index]->getCustomerID()) == customerID)
        {
            return customerTable[index];
        }
        index = (index + 1) % HASH_SIZE;
    }
    return nullptr;
}

bool HashTable::customerExists(const string &customerID)
{
    return search(customerID) != nullptr;
}