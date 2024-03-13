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

Customer *Business::getCustomer(int customerID)
{
    return customers.search(to_string(customerID));
}

void Business::runningCommands(const string &data)
{
    ifstream file(data);
    if (!file)
    {
        cerr << "ERROR: Invalid file" << endl;
        return;
    }

    string line;
    while (!file.eof())
    {
        char typeOfCommand;
        char typeOfMovie;
        file >> typeOfCommand;

        switch (typeOfCommand)
        {
        case 'B':
        {
            int customerID;
            file >> customerID;
            Customer *customer = getCustomer(customerID);
            if (customer == NULL)
            {
                cerr << "ERROR: Customer " << customerID << " does not exist" << endl;
                continue;
            }
            char format;
            file >> format;
            file >> typeOfMovie;
            borrowCommand(file, customer, typeOfMovie);
            break;
        }
        case 'R':
            // returnCommand(file, typeOfMovie);
            break;
        case 'I':
            movie.viewingInventory();
            break;
        case 'H':
            // historyCommand(file);
            break;
        default:
            cerr << "ERROR: Invalid command type " << typeOfCommand << endl;
        }
        getline(file, line);
    }
    file.close();
}

