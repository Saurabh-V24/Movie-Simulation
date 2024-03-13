#include "transaction.h"
using namespace std;


Transaction::Transaction(){
    setCustomerID(0);
}

Transaction::Transaction(char typeOfTransaction, int customerID, Movie *movie){
    setTypeOfTransaction(typeOfTransaction);
    setCustomerID(customerID);
    setMovie(movie);
}

Transaction::~Transaction(){
    movie = nullptr;
}

void Transaction::setCustomerID(int customerID){
    this->customerID = customerID;
}

void Transaction::setTypeOfTransaction(char transactionType){
    this->typeOfTransaction = transactionType;
}

void Transaction::setMovie(Movie *movie){
    this-> movie = movie;
}

int Transaction::getCustomerID() const{
    return this->customerID;
}

char Transaction::getTransactionType() const{
    return this->typeOfTransaction;
}

Movie* Transaction::getMovie() const{
    return this->movie;
}

void Transaction::doTrans(){  
}

void Transaction::display() const{
}

