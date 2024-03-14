// ------------------------------------------------ BST.h -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/12/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Header file for Binary Search Tree, used to store movies sorted
//           Comedy: sorted by title, then year released
//           Drama: sorted by director, then title
//           Classics: sorted by release date, then major actor

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include "movie.h"
using namespace std;

// Node
struct Node
{
    Node *left;
    Node *right;
    Movie *movie;
};

/**
 * The BST class provides functionality to add movies, retrieve movies by title and year,
 * reset the tree, and print the contents of the tree. It uses a binary search tree data structure implementation
 * to efficiently store and retrieve movies based on their titles.
 */
class BST
{
    // overload
    friend ostream &operator<<(ostream &, const BST &);

public:
    /**
     *  Default constructor for BST.
     */
    BST();

    /**
     * Destructor for BST.
     */
    ~BST();

    /**
     * Retrieves a movie from the tree based on its title and year.
     *
     * @param movie The movie object containing the title and year to search for.
     * @param foundMovie A pointer to the movie object where the found movie will be stored.
     */
    bool getMovie(const Movie &movie, Movie *&foundMovie) const;

    /**
     * Adds a movie to the tree.
     *
     * @param movie A pointer to the movie object to be added.
     */
    bool addMovie(Movie *&movie);

    /**
     * Retrieves a movie from the tree based on its title and year.
     *
     * @param title The title of the movie to search for.
     * @param year The year of the movie to search for.
     * @param foundMovie A pointer to the movie object where the found movie will be stored.
     */
    bool getMovieByTitle(string title, int year, Movie *&foundMovie);

    /**
     * Resets the tree by deleting all nodes and freeing memory.
     */
    void reset();

private:
    Node *root; // Pointer to the root node of the tree

    // helper functions for BST

    /**
     * Recursively deletes all nodes in the tree and frees memory.
     * @param cur The current node being processed.
     */
    void MakeEmpty(Node *&cur);

    /**
     * Recursively prints the contents of the tree in ascending order.
     * @param cur The current node being processed.
     */
    void printRec(Node *cur) const;

    /**
     * Recursively inserts a movie into the tree.
     *
     * @param cur A reference to the current node being processed.
     * @param movie A pointer to the movie object to be inserted.
     */
    bool insertRec(Node *&cur, Movie *&movie);

    /**
     * Recursively retrieves a movie from the tree based on its title and year.
     *
     * @param movie The movie object containing the title and year to search for.
     * @param foundMovie A pointer to the movie object where the found movie will be stored.
     * @param cur The current node being processed.
     */
    bool retrieveRec(const Movie &movie, Movie *&foundMovie, Node *cur) const;

    /**
     * Recursively resets the tree by deleting all nodes and freeing memory.
     *
     * @param cur The current node being processed.
     */
    void resetRec(Node *cur);

    /**
     * Recursively retrieves a movie from the tree based on its title and year.
     *
     * @param title The title of the movie to search for.
     * @param year The year of the movie to search for.
     * @param foundMovie A pointer to the movie object where the found movie will be stored.
     * @param cur The current node being processed.
     */
    bool getMovieByTitleRec(string title, int year, Movie *&foundMovie, Node *cur);
};

#endif /* BST_hpp */
