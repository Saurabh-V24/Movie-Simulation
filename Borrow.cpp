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
/**
 * doTrans: does borrow transaction with error handling
 * @param customerTable: the customer hashtable, (to add) MovieInventory: the movie inventory hashtable
 */
bool Borrow::doTrans(HashTable *customerTable)
{
    Customer *curr = customerTable->search(to_string(customer->getCustomerID()));
    // check if customer exists
    if (customerTable->customerExists(to_string(customer->getCustomerID())) == false)
    {
        cout << "ERROR: Borrow Transaction Failed -- "
             << "Customer " << customer->getCustomerID() << " does not exist" << endl;
        // delete movie ptr after bad borrow
        delete movie;
        movie = nullptr;
        return false;
    }
    // check if movie exists (replace with movie inv)
    if (movie == nullptr)
    {
        cout << "ERROR: Borrow Transaction Failed -- "
             << "Movie " << movie->getTitle() << " " << movie->getReleaseYear() << " does not exist in the Inventory" << endl;
        // delete movie ptr after bad borrow
        delete movie;
        movie = nullptr;
        return false;
    }
    // check if movie is in stock
    if (movie->getStock() == 0)
    {
        cout << "ERROR: Borrow Transaction Failed -- "
             << "Movie " << movie->getTitle() << " is out of stock" << endl;
        // delete movie ptr after bad borrow
        delete movie;
        movie = nullptr;
        return false;
    }
    setData();
    return true;
}

/**
 * setData: sets the data for the borrow transaction
 */
void Borrow::setData()
{
    // decrease stock by 1
    movie->decreaseStock(1);
    // add transaction to customer history
    customer->addTransaction(this);
}
// end of setDat

/**
 * display: displays the borrow transaction with the movie info
 * precondition: none
 * postcondition: displays the borrow transaction with the movie info
 */
string Borrow::display()
{
    // display the borrow transaction
    cout << "Borrow: " << movie->getTitle() << " " << movie->getDirector() << endl;
}
// end of display