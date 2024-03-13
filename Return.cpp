#include <Return.h>

Return::Return(){
    setTypeOfTransaction('R');
}

Return::Return(int customerID, Movie *movie){
    setTypeOfTransaction('R');
    setCustomerID(customerID);
    setMovie(movie);
}

Return::~Return(){
    this->movie = nullptr;
}

void Return::doTrans(){
    this->movie->increaseStock();
}

void Return::display()const{

    if(this->movie->getTypeOfMovie() == 'C'){
        cout << "Returned " << this->movie->getTitle() << "by " << this->movie->getDirector() << endl;
    }
    else if(this->movie->getTypeOfMovie() == 'F'){
        cout << "Returned " << this->movie->getTitle() << "by " << this->movie->getDirector() << endl;
    }
    else{
        cout << "Returned " << this->movie->getTitle() << "by " << this->movie->getDirector() << endl;
    }
}

