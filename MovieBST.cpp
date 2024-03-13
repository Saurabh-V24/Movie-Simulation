#include "MovieBST.h"

MovieBST::MovieBST(){
    root == nullptr;
}

void MovieBST::empty(Node *&curr){
    if(curr != nullptr){
        empty(curr->left);
        empty(curr->right);

        delete curr->movie;
        curr->movie = nullptr;
        delete curr;
        curr = nullptr;
    }
}

MovieBST::~MovieBST(){
    empty(root);
}

bool MovieBST::retrieve(const Movie& movie, Movie*& moviePtr, Node* curr) const{
    if(curr = nullptr){
        return false;
    }
    else if(*curr->movie == movie){
        moviePtr = curr->movie;
        return true;
    }
    else if(*curr-> movie > movie){
        return retrieve(movie, moviePtr, curr -> left);
        
    }
    else{
        return retrieve(movie, moviePtr, curr->right);
    }
}

bool MovieBST::gettingMovie(const Movie& movie, Movie*& moviePtr) const{
    return retrieve(movie, moviePtr, root);
}

bool MovieBST::insert(Node *& curr, Movie*& addMovie){
    if(curr == nullptr){
        curr = new Node;
        curr ->right == nullptr;
        curr -> left == nullptr;
        curr -> movie == addMovie;
        return true;
    }
    else if(*curr->movie == *addMovie){
        return false;
    }
    else if(*curr->movie > *addMovie){
        return insert(curr->left, addMovie);
    }
    else{
        return insert(curr->right, addMovie);
    }
}

bool MovieBST::addMovie(Movie *&movie){
    return insert(root, movie);
}

bool MovieBST::searchingMovieTitle(string title, int year, Movie *&moviePtr, Node *curr){
    if(curr == nullptr){
        return false;
    }
    else if(curr->movie->getTitle() == title && curr->movie->getReleaseYear() == year
    && !curr->movie->statusOfClassicMovie()){
        moviePtr = curr->movie;
        moviePtr->manageClassicStock(true);
        return true;

    }
    else{
        return searchingMovieTitle(title, year, moviePtr, curr->left) || searchingMovieTitle(title, year, moviePtr, curr->right);
    }
}

bool MovieBST::movieTitle(string title, int year, Movie*& moviePtr){
    return searchingMovieTitle(title, year, moviePtr, root);
}

void MovieBST::printInOrder(Node*curr)const{
    if(curr!= nullptr){
        printInOrder(curr->left);
        if(!curr->movie->statusOfClassicMovie()){
            curr->movie->display();
            curr->movie->manageClassicStock(true);
            cout << endl;
        }
        printInOrder(curr->right);
    }
}

void MovieBST::resetHelper(Node *curr){
    if(curr != nullptr){
        resetHelper(curr->left);
        curr->movie->manageClassicStock(false);
        resetHelper(curr->right);
    }
}

void MovieBST::reset(){
    resetHelper(root);
}

ostream &operator<<(ostream& out, const MovieBST& BST){
    BST.printInOrder(BST.root);
    cout<<endl;
    return out;
}