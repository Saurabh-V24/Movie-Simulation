// ------------------------------------------------ history.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS343 Section D

// 03/13/2024

// Date of Last Modification

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Implements history class. Displays the customer's transaction history

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
#include "history.h"

/**
 * History(): constructor for history
 * precondition: none
 * postcondition: none
 */
History::History(int customerID)
{
    customerID = customerID;
}
// end of constructor

/**
 * ~History(): destructor for history
 * precondition: none
 * postcondition: none
 */
History::~History()
{
}
// end of destructor

/**
 * doTrans: displays the customer's transaction history
 * precondition: none
 * postcondition: displays the customer's transaction history
 */
bool History::doTrans(Customer &customer)
{
    customer.getHistory();
    return true;
}
// end of doTrans

// // end of doTrans