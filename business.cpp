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
    switch (movieType)
    {
    case 'C':
    {
        int releaseMonth, releaseYear;
        commandsFile >> releaseMonth >> releaseYear;

        string firstName, lastName;
        commandsFile >> firstName >> lastName;

        string majorActor = firstName + " " + lastName;

        Movie *selection;
        bool validMovie = movie.searchingClassic(releaseMonth, releaseYear, majorActor, selection);

        if (validMovie)
        {
            Transaction *type = new Borrow('B', selection);
            Movie *selection = type->getMovie();

            int numBorrowed = 0;
            int numReturned = 0;

            for (int i = 0; i < customer->transactions.size(); i++)
            {
                if (movieType == selection->getTypeOfMovie())
                {
                    if (customer->transactions[i]->getMovie() == selection)
                    {
                        if (customer->transactions[i]->getTransactionType() == 'B')
                        {
                            numBorrowed++;
                        }
                        else if (customer->transactions[i]->getTransactionType() == 'R')
                        {
                            numReturned++;
                        }
                    }
                }
            }
            if (numBorrowed == numReturned)
            {
                type->doTrans();
                customer->addTransaction(type);
            }
            else
            {
                cerr << "ERROR: Borrow cannot occur" << endl;
                delete type;
                type = nullptr;
            }
        }
        break;
    }
    case 'D':
    {
        string director, title;
        getline(commandsFile, director, ',');
        getline(commandsFile, title, ',');

        Movie *selection;
        bool validMovie = movie.searchingDrama(director, title, selection);

        if (validMovie)
        {
            Transaction *type = new Borrow('B', selection);
            Movie *selection = type->getMovie();

            int numBorrowed = 0;
            int numReturned = 0;

            for (int i = 0; i < customer->transactions.size(); i++)
            {
                if (movieType == selection->getTypeOfMovie())
                {
                    if (customer->transactions[i]->getMovie() == selection)
                    {
                        if (customer->transactions[i]->getTransactionType() == 'B')
                        {
                            numBorrowed++;
                        }
                        else if (customer->transactions[i]->getTransactionType() == 'R')
                        {
                            numReturned++;
                        }
                    }
                }
            }
            if (numBorrowed == numReturned) // Possibly the issue
            {
                type->doTrans();
                customer->addTransaction(type);
            }
            else
            {
                cerr << "ERROR: Borrow cannot occur" << endl;
                delete type;
                type = nullptr;
            }
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
            Transaction *type = new Borrow('B', selection);
            Movie *selection = type->getMovie();

            int numBorrowed = 0;
            int numReturned = 0;

            for (int i = 0; i < customer->transactions.size(); i++)
            {
                if (movieType == selection->getTypeOfMovie())
                {
                    if (customer->transactions[i]->getMovie() == selection)
                    {
                        if (customer->transactions[i]->getTransactionType() == 'B')
                        {
                            numBorrowed++;
                        }
                        else if (customer->transactions[i]->getTransactionType() == 'R')
                        {
                            numReturned++;
                        }
                    }
                }
            }
            if (numBorrowed == numReturned)
            {
                type->doTrans();
                customer->addTransaction(type);
            }
            else
            {
                cerr << "ERROR: Borrow cannot occur" << endl;
                delete type;
                type = nullptr;
            }
        }
        break;
    }
    default:
    {
        cerr << "ERROR: Invalid movie type" << endl;
    }
    }
}

    // int main() {
    //     Business business;

    //     business.buildCustomer("data4customers.txt");

    //     // look for customers in business

    //     Customer* porky = business.getCustomer(8888);
    //     Customer* daffy = business.getCustomer(9999);
    //     Customer* mickey = business.getCustomer(1111);

    //     if (porky != nullptr) {
    //         cout << "Test passed: Found customer 8888\n";
    //     } else {
    //         cout << "Test failed: Could not find customer 8888\n";
    //     }

    //     if (daffy != nullptr) {
    //         cout << "Test passed: Found customer 9999\n";
    //     } else {
    //         cout << "Test failed\n";
    //     }

    //     if (mickey != nullptr) {
    //         cout << "Test passed: Found customer 1111\n";
    //     }
    // }