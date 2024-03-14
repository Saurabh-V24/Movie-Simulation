
#include "BST.h"

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    MakeEmpty(root);
}

void BST::MakeEmpty(Node *& cur)
{
    if (cur != nullptr) {
        // go left
        MakeEmpty(cur->left);
        // go right
        MakeEmpty(cur->right);
        
        // delete
        delete cur->movie;
        cur->movie = nullptr;
        delete cur;
        cur = nullptr;
    }
}

bool BST::getMovie(const Movie& m, Movie*& f) const
{
    return retrieveRec(m, f, root);
}

bool BST::retrieveRec(const Movie& m, Movie*& f, Node* cur) const
{
    // not found
    if (cur == NULL) return false;
    // found
    else if (*cur->movie == m)
    {
        f=cur->movie;
        return true;
    }
    // go left
    else if (*cur->movie > m)
        return retrieveRec(m, f, cur -> left);
    // go right
    else
        return retrieveRec(m, f, cur -> right);
    
}


ostream &operator<< (ostream& out, const BST& tree)
{
    tree.printRec(tree.root);
    cout << endl;
    return out;
}


bool BST::addMovie(Movie *&m)
{
    return insertRec(root, m);
}

bool BST::insertRec(Node *& cur, Movie*& newM)
{
    // if nowhere to go
    if (cur == nullptr) {
        cur = new Node;
        cur->right = nullptr;
        cur->left = nullptr;
        cur->movie = newM;
        return true;
    }
    // already here
    else if (*cur->movie == *newM) return false;
    // go left
    else if (*cur->movie > *newM) return insertRec(cur->left, newM);
    // go right
    else return insertRec(cur->right, newM);
}


bool BST::getMovieByTitle(string title, int year, Movie*& f)
{
    return getMovieByTitleRec(title, year, f, root);
}

bool BST::getMovieByTitleRec(string title, int year, Movie *&f, Node *cur)
{
    // no movie
    if (cur==nullptr) return false;
    // yes movie
    else if (cur->movie->getTitle()==title &&
             cur->movie->getYear()==year   &&
             !cur->movie->get_Cstat()) {
        f = cur->movie;
        f->setC(true);
        return true;
    }
    else return getMovieByTitleRec(title, year, f, cur->left) || getMovieByTitleRec(title, year, f, cur->right);
}


void BST::printRec(Node *cur) const
{
    // if not the last node
    if (cur!=nullptr) {
        // go left
        printRec(cur->left);
        // print
        if (!cur->movie->get_Cstat()) {
            cur->movie->display();
            cur->movie->setC(true);
            cout << endl;
        }
        // go right
        printRec(cur->right);
    }
}

void BST::reset()
{
    resetRec(root);
}


void BST::resetRec(Node * cur)
{
    if (cur!=nullptr) {
        resetRec(cur->left);
        cur->movie->setC(false);
        resetRec(cur->right);
    }
}

