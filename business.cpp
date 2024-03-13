#include "business.h"

Business::Business()
{
}

Business::Business(string const &file)
{

    movie.buildInventory(file);
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
            cerr << "Error reading line: " << line << endl;
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

// reading commands
void Business::readCommands(const string &file)
{
    ifstream inFile;
    inFile.open(file);
    if (!inFile.is_open())
    {
        cerr << "Unable to open file: " << file << endl;
    }

    string line;
    while (getline(inFile, line))
    {
        istringstream split(line);
        char command;
        split >> command;
        // check if command is valid
        if (command != 'B' && command != 'R' && command != 'I' && command != 'H')
        {
            cerr << "Invalid command: " << command << endl;
            continue;
        }

        // process transaction
        if (command == 'B')
        {
            int customerID;
            string mediaType, movieType;
            int releaseYear;
            string title;
            split >> customerID >> mediaType >> movieType >> releaseYear;
            getline(split, title);
            title = title.substr(1);
            // get customer from hashtable
            Customer *customer = customers.search(to_string(customerID));
            // get movie from inventory
            Movie *movie = movie.search(mediaType, movieType, releaseYear, title);
            Transaction *borrow = new Borrow(customer, movie);
            // does specified transaction
            borrow->doTrans();
        }
        else if (command == 'R')
        {
            int customerID;
            string mediaType, movieType;
            int releaseYear;
            string title;
            split >> customerID >> mediaType >> movieType >> releaseYear;
            getline(split, title);
            title = title.substr(1);
            // get customer from hashtable
            Customer *customer = customers.search(to_string(customerID));
            // get movie from inventory
            Movie *movie = movie.search(mediaType, movieType, releaseYear, title);
            Transaction *returnTrans = new Return(customer, movie);
            // does specified transaction
            returnTrans->doTrans();
        }
        else if (command == 'H')
        {
            // call history transaction
            int customerID;
            split >> customerID;
            Customer *customer = customers.search(to_string(customerID));
            Transaction *history = new History(customerID);
            history->doTrans(); // Remove the unnecessary argument
        }
    }
}

/**
 * processTransaction: processes the transaction
 * precondition: none
 * postcondition: processes the transaction
 */
