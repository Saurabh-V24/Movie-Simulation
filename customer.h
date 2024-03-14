//---------------------------------------------------------------------------
// customer.h
//---------------------------------------------------------------------------
// CSS 343 B
// Creation Date: 05/12/2023
//---------------------------------------------------------------------------
// This is the description of customer class
//
//---------------------------------------------------------------------------
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
    void addCheckedOut(Movie*);
    bool removeCheckedOut(Movie*);
    
private:
    struct checkedOutNode {
        checkedOutNode* next;
        Movie* borrowed_m;
    };
    // for history tracking
    struct historyNode {
        historyNode* next;
        string data;
    };
    
    string lastName;
    string firstName;
    int ID;
    historyNode *history;
    checkedOutNode *checkedOut;
};
#endif
