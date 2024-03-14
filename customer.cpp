#include "customer.h"

// constructors
Customer::Customer()
{
    firstName="SamlpeFname";
    lastName="SampleLname";
    ID = 0;
    history = nullptr;
    checkedOut = nullptr;
}

Customer::Customer(int id, string first, string last)
{
    ID = id;
    firstName = first;
    lastName = last;
    history = nullptr;
    checkedOut = nullptr;
    
}

// destructor
Customer::~Customer()
{
    // delete history
    historyNode* t = history;
    while (t!=nullptr) {
        history = history->next;
        delete t;
        t = history;
    }
    // delete checkedOut
    checkedOutNode* c = checkedOut;
    while (c!=nullptr) {
        checkedOut = checkedOut->next;
        delete c->borrowed_m;
        c->borrowed_m = nullptr;
        delete c;
        c = checkedOut;
    }
}

// display customer
void Customer::display()
{
    string z0 = "";
    if (ID < 10) z0 = "000";
    else if (ID<100) z0="00";
    else if (ID<1000) z0="0";
    cout << z0 << ID << "    ";
    cout.width(10);
    cout << left << firstName;
    cout.width(10);
    cout << left << lastName << endl;
}

// output history
void Customer::displayHistory()
{
    cout << endl;
    cout << "History for " << getName() << ":" << endl;
    historyNode* his = history;
    while (his!=NULL) {
        cout << his->data << endl;
        his=his->next;
    }
    cout << endl;
}

// getters
int Customer::getID()
{
    return ID;
}

string Customer::getName()
{
    return firstName + " " + lastName;
}

// adders
void Customer::addHistory(string s)
{
    historyNode* newHis = new historyNode;
    newHis->data = s;
    newHis->next = history;
    history = newHis;
}


void Customer::addCheckedOut(Movie * m)
{
    checkedOutNode* newM = new checkedOutNode;
    newM->borrowed_m = m;
    newM->next = checkedOut;
    checkedOut = newM;
}

// remove checked out item
bool Customer::removeCheckedOut(Movie * m)
{
    checkedOutNode *c = checkedOut;
    if (c!=nullptr) {
        if (*(c->borrowed_m) == *m) {
            delete checkedOut->borrowed_m;
            checkedOut = c->next;
            delete c;
            c = nullptr;
            return true;
        }
        checkedOutNode* before = c;
        c=c->next;
        while (c!=nullptr) {
            if (*(c->borrowed_m) == *m) {
                delete c->borrowed_m;
                before->next = c->next;
                c->next = nullptr;
                delete c;
                return true;
            }
            before = c;
            c = c->next;
        }
    }
    return false;
}
