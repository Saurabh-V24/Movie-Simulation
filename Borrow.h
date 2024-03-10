#ifndef BORROW_H
#define BORROW_H
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"

class Borrow : public Transaction{
public: 
    Borrow();
    Borrow(int customerID, Movie *movie);
    ~Borrow();
    void doTrans();
    void display();
};
#endif
