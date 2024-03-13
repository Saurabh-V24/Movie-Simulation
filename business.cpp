#include "business.h"

Business::Business()
{
}

Business::~Business()
{
}

void Business::buildCustomer(const string &filename)
{
    // open the file
    ifstream inFile;
    inFile.open(filename);
    // return an error if file cannot be opened
    if (!inFile.is_open())
    {
        cerr << "Unable to open file: " << filename << endl;
        // student list is empty
    }
    string line;
    // read each line of the file
    while (getline(inFile, line))
    {
        istringstream split(line);
        int customerID;
        string lastName, firstName;
        // check if file is formatted
        if (!(split >> customerID >> lastName >> firstName))
        {
            cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        // check if customerID is already in system
        if (customers.search(to_string(customerID)) == nullptr)
        {
            // add customer to hashtable
            Customer customer(customerID, lastName, firstName);
            customers.insert(customer);
        }
    }
    inFile.close();
}

Customer *Business::getCustomer(int customerID)
{
    return customers.search(to_string(customerID));
}

int main()
{
    Business business;

    business.buildCustomer("data4customers.txt");

    // look for customers in business

    Customer *porky = business.getCustomer(8888);
    Customer *daffy = business.getCustomer(9999);
    Customer *mickey = business.getCustomer(1111);

    if (porky != nullptr)
    {
        cout << "Test passed: Found customer 8888\n";
    }
    else
    {
        cout << "Test failed: Could not find customer 8888\n";
    }

    if (daffy != nullptr)
    {
        cout << "Test passed: Found customer 9999\n";
    }
    else
    {
        cout << "Test failed\n";
    }

    if (mickey != nullptr)
    {
        cout << "Test passed: Found customer 1111\n";
    }
}