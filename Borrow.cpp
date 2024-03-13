using namespace std;
#include "Borrow.h"

Borrow::Borrow(Customer *customer, Movie *movie)
{
    this->customer = customer;
    this->movie = movie;
}

Borrow::~Borrow()
{
}

bool Borrow::doTrans(HashTable* customerTable)
{
    Customer *curr = customerTable->search(customer->getCustomerID());
    // check if customer exists
    if (customerTable->customerExists(customer->getCustomerID()) == false)
    {
        cout << "ERROR: Borrow Transaction Failed -- "
             << "Customer " << customer->getCustomerID() << " does not exist" << endl;
        // delete movie ptr after bad borrow
        delete movie;
        movie = nullptr;
        return false;
    }
    if(movie->getStock() == 0){
        cout << "ERROR: Borrow Transaction Failed -- "
             << "Movie " << movie->getTitle() << " is out of stock" << endl;
        // delete movie ptr after bad borrow
        delete movie;
        movie = nullptr;
        return false;
    }
    // check if movie exists
    this->movie->decreaseStock();
}

string Borrow::display()
{
}
