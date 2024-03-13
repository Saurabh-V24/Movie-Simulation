#ifndef RETURN_H
#define RETURN_H
#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
using namespace std;

class Return : public Transaction
{
public:
    Return();
    Return(int customerID, Movie *movie);
    ~Return();
    
    void doTrans();
    void display()const;
};
#endif