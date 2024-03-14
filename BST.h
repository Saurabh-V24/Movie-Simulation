#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include "movie.h"
using namespace std;

// Node
struct Node
{
    Node* left;
    Node* right;
    Movie* movie;
};

class BST
{
    // overload
    friend ostream& operator << (ostream&, const BST&);
public:
    BST();
    ~BST();
    
    bool getMovie (const Movie&, Movie*&) const;
    bool addMovie(Movie*&);
    bool getMovieByTitle (string, int, Movie*&);
    void reset();
private:
    Node* root;
    // helpers
    void MakeEmpty(Node *&);
    
    void printRec(Node* cur) const;
    
    bool insertRec (Node *&, Movie*&);
    bool retrieveRec (const Movie&, Movie*& , Node*) const;
    void resetRec(Node*);
    
    bool getMovieByTitleRec (string title, int year, Movie*&, Node*);
};

#endif /* BST_hpp */
