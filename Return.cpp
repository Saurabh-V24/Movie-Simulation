#include "Return.h"

Return::Return(Customer *customer, Movie *movie)
{
    this->customer = customer;
    this->movie = movie;
}

Return::~Return() {}

/**
 * doTrans: does return transaction with error handling
 * @param customerTable: the customer hashtable, (to add) MovieInventory: the movie inventory hashtable
 */
bool Return::doTrans(HashTable *customerTable)
{
    // if the movie is not borrowed, return false
    if (customerTable->customerExists(to_string(customer->getCustomerID())) == false)
    {
        cout << "ERROR: Return Transaction Failed -- "
             << "Customer " << customer->getCustomerID() << " does not exist" << endl;
        delete movie;
        movie = NULL;
        return false;
    }
    if (movie != nullptr)
    {
        // check if movie exists in inventory (replace with movie inv)
        if (movie->decreaseStock(1) == true)
        {
            setData();
            return true;
        }
        else
        {
            cout << "ERROR: Return Transaction Failed -- "
                 << "Movie " << movie->getTitle() << " " << movie->getReleaseYear() << " Movie does not Exist in Inventory" << endl;
            delete movie;
            movie = NULL;
            return false;
        }
    }
}
// end of doTrans

/**
 * setData: sets the data for the return transaction
 * precondition: none
 * postcondition: sets the data for the return transaction
 */
void Return::setData()
{
    // increase stock by 1
    movie->increaseStock(1);
    // add transaction to customer history
    customer->addTransaction(this);
}

/**
 * display: displays the return transaction
 * precondition: none
 * postcondition: displays the return transaction
 */
string Return::display()
{
    cout << "Returned: " << movie->getTitle() << " " << movie->getDirector() << endl;
}
// end of display