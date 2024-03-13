#include "transaction.h"
using namespace std;

Transaction::Transaction()
{
    transType = ' ';
}
Transaction::~Transaction() {}
// here to be overidden
bool Transaction::doTrans() {}

// here to be overridden
string Transaction::display() {}

// here to be overridden
void Transaction::setData() {}