#ifndef BST_CPP
#define BST_CPP
#include <iostream>
#include "Movie.h"
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    Movie* movie;
};

class MovieBST{
    friend ostream& operator<<(ostream&, const MovieBST& );

public:
    MovieBST();
    ~MovieBST();
    bool gettingMovie(const Movie&, Movie*&) const;
    bool addMovie(Movie *&);
    bool movieTitle(string, int, Movie*&);
    void reset();
private:
    Node *root;
    void empty(Node *&);
    void printInOrder(Node*) const;
    bool insert(Node*&, Movie*&);
    bool retrieve(const Movie&, Movie*&, Node*) const;
    bool searchingMovieTitle(string, int year, Movie*&, Node*);
    void resetHelper(Node*);

};
#endif