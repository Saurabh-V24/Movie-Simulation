#include "Return.h"

Return::Return(Customer *customer, Movie *movie)
{
    this->customer = customer;
    this->movie = movie;
}

Return::~Return() {}

/**
 * doTrans: performs the return transaction
 */
bool Return::doTrans()
{
    // if the movie is not borrowed, return false
    if (movie->getStock() <= 0)
    {
        return false;
    }
    // if the movie is borrowed, return true
    else
    {
        // increase stock by 1
        setData();
        return true;
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
    movie->increaseStock();
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
    cout << "Returned: " << movie->getTitle() << " " << movie->getReleaseYear() << endl;
}
// end of display