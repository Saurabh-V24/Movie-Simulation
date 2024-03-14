// ------------------------------------------------ customer.h -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/13/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Header file for customer class, used to store customer information
//           Uses nodes to store history and checked out movies
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
#ifndef customer_h
#define customer_h

#include <iostream>
#include "movie.h"
#include "MovieFactory.h"
using namespace std;

class Customer
{
public:
    Customer();
    Customer(int, string, string);
    ~Customer();

    void display();
    void displayHistory();

    int getID();
    string getName();

    void addHistory(string);
    void addCheckedOut(Movie *);
    bool removeCheckedOut(Movie *);

private:
    struct checkedOutNode
    {
        checkedOutNode *next;
        Movie *borrowed_m;
    };
    // for history tracking
    struct historyNode
    {
        historyNode *next;
        string data;
    };

    string lastName;
    string firstName;
    int ID;
    historyNode *history;
    checkedOutNode *checkedOut;
};
#endif
