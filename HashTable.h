class HashTable {
private:
    static const int HASH_SIZE = 100;
    std::vector<Customer*> table;

    int hashFunction(const std::string &key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % HASH_SIZE;
        }
        return hash;
    }

public:
    HashTable() {
        table.resize(HASH_SIZE, nullptr);
    }

    ~HashTable() {
        for (Customer* customer : table) {
            delete customer;
        }
    }

    void insert(const Customer &customer) {
        int index = hashFunction(customer.getCustomerID());
        while (table[index] != nullptr) {
            index = (index + 1) % HASH_SIZE;
        }
        table[index] = new Customer(customer);
    }

    Customer* search(const std::string &customerID) {
        int index = hashFunction(customerID);
        while (table[index] != nullptr) {
            if (table[index]->getCustomerID() == customerID) {
                return table[index];
            }
            index = (index + 1) % HASH_SIZE;
        }
        return nullptr;
    }
};