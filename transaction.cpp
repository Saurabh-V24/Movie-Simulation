#include "transaction.h"

Transaction::Transaction()
{
    t_type = 'Z';
}

Transaction::~Transaction(){}

// empty function, never used, just for overload
bool Transaction::perform(MovieInventory& ms, CustomerInventory& cs)
{
    return true;
}

//-------------------------------History--------------------------------------

// constructor
History::History(int id)
{
    ID = id;
}

History::~History() {}

// show history
bool History::perform(MovieInventory &ms, CustomerInventory &cs)
{
    // customer is invalid
    if (!cs.customerExisting(ID)) {
        cout << "ERROR: History Transaction Failed -- " << "Customer " << ID << " does not exist" << endl;
        return false;
    }
    // get customer
    Customer *c = cs.getCustomer(ID);
    // show history
    c->displayHistory();
    return true;
}

//-------------------------------Borrow--------------------------------------

// constructor
Borrow::Borrow(int id, Movie* m)
{
    ID = id;
    movie = m;
}

Borrow::~Borrow() {}

// borrow movie
bool Borrow::perform(MovieInventory &ms, CustomerInventory &cs)
{
    // no such customer
    if (!cs.customerExisting(ID)) {
        cout << "ERROR: Borrow Transaction Failed -- " << "Customer " << ID << " does not exist" << endl;
        // delete movie ptr after bad borrow
        delete movie;
        movie = nullptr;
        return false;
    }
    // get customer
    Customer* customer = cs.getCustomer(ID);
    if (movie != nullptr) {
        // if movie exists
        if (ms.if_movie_exists(movie)) {
            string info = "";
            if (ms.borrowMovie(movie, info)) {
                // adding history + borrowing
                string borrow_info = "Borrowed " + info;
                customer->addCheckedOut(movie);
                customer->addHistory(borrow_info);
                return true;
            }
            else cout << "ERROR: Borrow Transaction Failed -- " << "Not enough in the Stock" << endl;
        }
        else cout << "ERROR: Borrow Transaction Failed -- " << "Movie does not Exist in the Inventory" << endl;
    }
    // no memory leaks
    delete movie;
    movie = nullptr;
    return false;
}

//-------------------------------Return--------------------------------------

// constructor
Return::Return(int id, Movie* m)
{
    ID = id;
    movie = m;
}

Return::~Return() {}

int Return::getCustomerID()
{
    return ID;
}

// returning the movie
bool Return::perform(MovieInventory & ms, CustomerInventory &cs)
{
    // if there is such customer
    if (!cs.customerExisting(ID)) {
        cout << "ERROR: Return Transaction Failed -- " << "Customer " << ID << " does not exist" << endl;
        
        // delete movie ptr after failed return transaction
        delete movie;
        movie = NULL;
                
        return false;
    }
    // get customer
    Customer *customer = cs.getCustomer(ID);
    if (movie!=nullptr) {
        // if exists
        if (ms.if_movie_exists(movie)) {
            // mark movie
            bool check = customer->removeCheckedOut(movie);
            if (check) {
                string info="";
                // return it
                ms.returnMovie(movie, info);
                string return_info = "Returned " + info;
                customer->addHistory(return_info);
                delete movie;
                movie = nullptr;
                return true;
            }
            else cout << "ERROR: Return Transaction Failed -- " << "Movie was Not Checked Out By the Customer" << endl;
        }
        else cout << "ERROR: Return Transaction Failed -- " << "Movie does not Exist in the Inventory" << endl;
    }
    delete movie;
    movie = nullptr;
    return false;
}

