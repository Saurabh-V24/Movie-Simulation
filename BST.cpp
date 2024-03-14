// ------------------------------------------------ BST.cpp -------------------------------------------------------

// Bruce Duong, Saurabh Vasdev CSS 343 Section D

// 03/02/2024

// 03/12/2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Binary Search Tree, used to store movies sorted
//           Comedy: sorted by title, then year released
//           Drama: sorted by director, then title
//           Classics: sorted by release date, then major actor

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
#include "BST.h"

/**
 * Constructor BST
 * preconditions: none
 * postconditions: sets root to nullptr
 */
BST::BST()
{
    root = nullptr;
}
// end of constructor

/**
 * Destructor BST
 * preconditions: none
 * postconditions: deletes all nodes in the tree

*/
BST::~BST()
{
    MakeEmpty(root);
}
// end of destructor

/**
 * MakeEmpty: helper function to delete all nodes in the tree
 * preconditions: none
 * postconditions: deletes all nodes in the tree
 */
void BST::MakeEmpty(Node *&cur)
{
    if (cur != nullptr)
    {
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
// end of MakeEmpty

/**
 * getMovie: retrieves a movie from the tree
 * preconditions: none
 * postconditions: returns true if movie is found, false otherwise
 */

bool BST::getMovie(const Movie &m, Movie *&f) const
{
    return retrieveRec(m, f, root);
}
// end of getMovie

/**
 * retrieveRec: helper function to getMovie
 * preconditions: none
 * postconditions: returns true if movie is found, false otherwise
 */
bool BST::retrieveRec(const Movie &m, Movie *&f, Node *cur) const
{
    // not found
    if (cur == NULL)
        return false;
    // found
    else if (*cur->movie == m)
    {
        f = cur->movie;
        return true;
    }
    // go left
    else if (*cur->movie > m)
        return retrieveRec(m, f, cur->left);
    // go right
    else
        return retrieveRec(m, f, cur->right);
}
// end of retrieveRec

/**
 * operator<<: overloads the << operator to print the tree
 * preconditions: none
 * postconditions: prints the tree
 */
ostream &operator<<(ostream &out, const BST &tree)
{
    tree.printRec(tree.root);
    cout << endl;
    return out;
}

/**
 * printRec: helper function to operator<<
 * preconditions: none
 * postconditions: prints the tree in order
 */
void BST::printRec(Node *cur) const
{
    // if not the last node
    if (cur != nullptr)
    {
        // go left
        printRec(cur->left);
        // print
        if (!cur->movie->get_Cstat())
        {
            cur->movie->display();
            cur->movie->setC(true);
            cout << endl;
        }
        // go right
        printRec(cur->right);
    }
}
// end of printRec

/**
 * addMovie: adds a movie to the tree
 * preconditions: none
 * postconditions: returns true if movie is added, false otherwise
 */
bool BST::addMovie(Movie *&m)
{
    return insertRec(root, m);
}
// end of addMovie

/**
 * insertRec: helper function to addMovie
 * preconditions: none
 * postconditions: returns true if movie is added, false otherwise
 */
bool BST::insertRec(Node *&cur, Movie *&newM)
{
    // no movie
    if (cur == nullptr)
    {
        cur = new Node;
        cur->right = nullptr;
        cur->left = nullptr;
        cur->movie = newM;
        return true;
    }
    // already here
    else if (*cur->movie == *newM)
        return false;
    // go left
    else if (*cur->movie > *newM)
        return insertRec(cur->left, newM);
    // go right
    else
        return insertRec(cur->right, newM);
}
// end of insertRec

/**
 * getMovieByTitle: retrieves a movie by title
 * preconditions: none
 * postconditions: returns true if movie is found, false otherwise
 */
bool BST::getMovieByTitle(string title, int year, Movie *&f)
{
    return getMovieByTitleRec(title, year, f, root);
}
// end of getMovieByTitle

/**
 * getMovieByTitleRec: helper function to getMovieByTitle
 * preconditions: none
 * postconditions: returns true if movie is found, false otherwise
 */
bool BST::getMovieByTitleRec(string title, int year, Movie *&f, Node *cur)
{
    // no movie
    if (cur == nullptr)
        return false;
    // yes movie
    else if (cur->movie->getTitle() == title &&
             cur->movie->getYear() == year &&
             !cur->movie->get_Cstat())
    {
        f = cur->movie;
        f->setC(true);
        return true;
    }
    else
        return getMovieByTitleRec(title, year, f, cur->left) || getMovieByTitleRec(title, year, f, cur->right);
}
// end of getMovieByTitleRec

/**
 * reset: resets the counted status of all movies
 * preconditions: none
 * postconditions: resets the counted status of all movies
 */
void BST::reset()
{
    resetRec(root);
}
// end of reset

/**
 * resetRec: helper function to reset
 * preconditions: none
 * postconditions: resets the counted status of all movies
*/
void BST::resetRec(Node *cur)
{
    if (cur != nullptr)
    {
        resetRec(cur->left);
        cur->movie->setC(false);
        resetRec(cur->right);
    }
}
// end of resetREc