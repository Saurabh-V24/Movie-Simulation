#include <iostream>
#include <string>
#include <array>

using namespace std;

class Customer;

class HashTable {
private:
    static const int HASH_SIZE = 10000;
    array<Customer*, HASH_SIZE> customerTable;
    int hashFunction(const string &key);

public:
    HashTable();

    ~HashTable();

    void insert(const Customer &customer);

    Customer* search(const string &customerID);
};