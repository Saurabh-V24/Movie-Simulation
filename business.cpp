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

void Business::borrowCommand(ifstream &commandsFile, Customer *customer, char movieType)
{
    // switch statement to determine the type of movie to perform transaction on
    switch (movieType)
    {
    // classic movie
    case 'C':
    {
        // get attributes for movie to check if it exists
        int releaseMonth, releaseYear;
        commandsFile >> releaseMonth >> releaseYear;

        string firstName, lastName;
        commandsFile >> firstName >> lastName;

        string majorActor = firstName + " " + lastName;

        Movie *selection;
        // Check if movie exists
        bool validMovie = movie.searchingClassic(releaseMonth, releaseYear, majorActor, selection);

        // if movie exists, perform transaction
        if (validMovie)
        {
            // create transaction object
            Transaction *type = new Borrow('B', selection);
            Movie *selection = type->getMovie();
            // check if stock is available
            if (selection->getStock() > 0)
            {
                // stock is updated
                type->doTrans();
                // transaction is added to customer's transaction history
                customer->addTransaction(type);
            }
            // not enough movies in stock
            else
            {
                cerr << "ERROR: Borrow Transaction Failed -- Not enough in the Stock " << endl;
                delete type;
                type = nullptr;
            }
        }
        // movie does not exist, throw error
        else
        {
            cerr << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory " << endl;
        }
        break;
    }
    // drama movie
    case 'D':
    {
        string director, title;
        getline(commandsFile, director, ',');
        getline(commandsFile, title, ',');

        Movie *selection;
        bool validMovie = movie.searchingDrama(director, title, selection);

        if (validMovie)
        {
            // create transaction object
            Transaction *type = new Borrow('B', selection);
            Movie *selection = type->getMovie();
            // check if stock is available
            if (selection->getStock() > 0)
            {
                // stock is updated
                type->doTrans();
                // transaction is added to customer's transaction history
                customer->addTransaction(type);
            }
            // not enough movies in stock
            else
            {
                cerr << "ERROR: Borrow Transaction Failed -- Not enough in the Stock " << endl;
                delete type;
                type = nullptr;
            }
        }
        // movie does not exist, throw error
        else
        {
            cerr << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory " << endl;
        }
        break;
    }

    case 'F':
    {
        string title;
        int releaseYear;
        getline(commandsFile, title, ',');
        commandsFile >> releaseYear;

        Movie *selection;
        bool validMovie = movie.searchingComedy(title, releaseYear, selection);

        if (validMovie)
        {
            // create transaction object
            Transaction *type = new Borrow('B', selection);
            Movie *selection = type->getMovie();
            // check if stock is available
            if (selection->getStock() > 0)
            {
                // stock is updated
                type->doTrans();
                // transaction is added to customer's transaction history
                customer->addTransaction(type);
            }
            // not enough movies in stock
            else
            {
                cerr << "ERROR: Borrow Transaction Failed -- Not enough in the Stock " << endl;
                delete type;
                type = nullptr;
            }
        }
        // movie does not exist, throw error
        else
        {
            cerr << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory " << endl;
        }
        break;
    }
    default:
    {
        cerr << "ERROR: Invalid movie type" << endl;
    }
    }
}