using namespace std;
#include <Borrow.h>

Borrow::Borrow(){
    setTypeOfTransaction('B');
}

Borrow::Borrow(int customerID, Movie *movie){
    setTypeOfTransaction('B');
    setCustomerID(customerID);
    setMovie(movie);
}

Borrow::~Borrow(){
    this->movie = nullptr;
}

void Borrow::doTrans(){
    this->movie->decreaseStock();
}

void Borrow::display()
{
    cout << "Borrowed " << this->movie->getTitle() << " by " << this->movie->getDirector() << endl;
}
