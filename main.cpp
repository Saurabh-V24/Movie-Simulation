#include <iostream>
#include <fstream>
#include "business.h"
using namespace std;

int main()
{
    ifstream customerFile("data4customers.txt");
    ifstream movieFile("data4movies.txt");
    ifstream transactionFile("data4commands.txt");
    
    if (!customerFile)                // repeat for movieFile and transactionFile
        cout << "Customer file cannot be oppened" << endl;
    if (!movieFile)                   // repeat for movieFile and transactionFile
        cout << "Movie file cannot be oppened" << endl;
    if (!transactionFile)             // repeat for movieFile and transactionFile
        cout << "Transaction file cannot be oppened" << endl;
    
    Business movieStore;                                   //create a store
    movieStore.readCustomerFile(customerFile);          //create customer profiles from file
    movieStore.readMovieFile(movieFile);                //create movie inventory from file
    movieStore.readTransactionFile(transactionFile);    //process transactions from file
    

    
    return 0;
}
