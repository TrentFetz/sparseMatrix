// Trent Fetzer(TJF20BJ) for
// COP4530 as Assignment 0

/* Implementation file for the List class
 * contains the function defintions for each of the
 * member functions of the Node ad List classes
 * Detailed descritions are included where necessary
 */

#include <iostream>
#include <sstream>
#ifndef LIST_H
#include "list.h"
#endif
using namespace std;

/* Parameterized constructor for the Node class
 * Creates a Node object of the required type, sets the
 * value to the given value, and sets the next pointer to NULL
 */
template <class T>
Node<T>::Node(T v, int col)
{
    val = v;
    next = NULL;
    colNum = col;
}

// getter for the value
template <class T>
T Node<T>::getVal() const
{
    return val;
}

// getter for the next pointer
template <class T>
Node<T> *Node<T>::getNext() const
{
    return next;
}

// setter for the value
template <class T>
void Node<T>::setVal(T v)
{
    val = v;
}

// setter for the next pointer
template <class T>
void Node<T>::setNext(Node<T> *n)
{
    next = n;
}
// setter for the column number
template <class T>
void Node<T>::setColNum(int c)
{
    colNum = c;
}

// getter for the column number
template <class T>
int Node<T>::getColNum() const
{
    return colNum;
}

/* default constructor for a List object
 * sets the Head pointer to NULL indicating an empty list
 */
template <class T>
List<T>::List()
{
    head = NULL;
}

/* Function to check if the list is empty
 * The list is empty if the head pointer is NULL
 */
template <class T>
bool List<T>::isEmpty() const
{
    if (head == NULL)
        return true;
    return false;
}

/* Function to return the size of the list.
 * The function counts every Node in the list before moving
 * to the next node. We have reached the end of the list when
 * the next node is NULL
 */
template <class T>
int List<T>::size() const
{
    int count = 0;
    Node<T> *cur = head;
    while (cur != NULL)
    {
        count++;
        cur = cur->getNext();
    }
    return count;
}

/* Function to add an element to the end of the list.
 * We create a new Node object for the given item.
 * Then, we traverse the list to the end using the same
 * logic as the size() function, and then attach the new
 * Node at the end
 */
template <class T>
void List<T>::addElement(T v, int col)
{
    Node<T> *cur, *incoming;
    // create a new Node
    incoming = new Node<T>(v, col);

    cur = head;
    // List was empty
    if (cur == NULL)
    {
        head = incoming;
    }
    else
    {
        // move to the end of the list
        while (cur->getNext() != NULL)
        {
            cur = cur->getNext();
        }
        // attach the new node at the end
        cur->setNext(incoming);
        
    }
    incoming->setColNum(col);
}

/* Function to cleare out the List.
 * Start at the head. Capture the next node so that we do not
 * lose the rest of the list. Then delete the current node.
 * Repeat until the next Node is NULL (end of the list)
 */
template <class T>
void List<T>::clear()
{
    Node<T> *cur, *element;
    cur = head;
    while (cur != NULL)
    {
        element = cur;        // pointer to the current node
        cur = cur->getNext(); // move to the next node
        delete element;       // delete the "current" node
    }
    head = NULL;
}

/* Destructor.
 * Use the clear function to empty out the list
 */
template <class T>
List<T>::~List()
{
    if (head != NULL)
        clear();
}

/* Function to print the contents of the list.
 * Traverse the list, printing the item at the current node
 * as we go.
 * This assumes the << opertaor has been overloaded for
 * all types that instantiate the list
 */

template <class T>
void List<T>::print() const
{
    Node<T> *cur = head;
    while (cur != NULL)
    {

        cout << cur->getColNum() << ", " << cur->getVal() << "\t";
        cur = cur->getNext();
    }
    cout << endl;
}

/* Function to insert an element at the given position
 * If the given position is invalid (negative, or greater than the
 * size of the list, the function fails and returns false
 * Otherwise, move through the list until we reach the given
 * position and then
 * (a) Set the new node's next pointer to the current node's next
 * (b) set the current node's next pointer to the new node
 */
template <class T>
bool List<T>::insert(T val, int col)
{

    // create a new node
    Node<T> *newNode = new Node<T>(val, col);
    if (head == NULL || col < head->getColNum())
    {
        newNode->setNext(head);
        head = newNode;
    }
    else
    {
        Node<T> *cur = head;
        while (cur->getNext() != NULL && cur->getNext()->getColNum() < col)
        {
            cur = cur->getNext();
        }
        newNode->setNext(cur->getNext());
        cur->setNext(newNode);
    }
    return true;
}

/* Function to remove en element from the list.
 * Function fails if the element were not found
 * Traverse the list until the element is located.
 * Set the previous node's next pointer to the target
 * node's next pointer
 * Then, delete the target node
 */
template <class T>
bool List<T>::remove(T val)
{
    Node<T> *cur = head, *pre = head;
    bool done = false;
    // Special case: remove the node at the head of the list
    if (head->getVal() == val)
    {
        head = head->getNext();
        delete cur;
        cur = NULL;
        done = true;
    }
    // locate the item
    while (cur != NULL && !done)
    {
        if (cur->getVal() == val)
        {
            pre->setNext(cur->getNext());
            delete cur;
            done = true;
        }
        // set the pointers as described
        pre = cur;
        cur = cur->getNext();
    }
    return done;
}

/* Linear search for an item
 * Returns truw if the item were found and false otherwise
 */
template <class T>
bool List<T>::search(T val) const
{
    Node<T> *cur = head;
    bool found = false;
    while (cur != NULL && !found)
    {
        if (cur->getVal() == val)
            found = true;
        cur = cur->getNext();
    }
    return found;
}

/* Copy constructor */
template <class T>
List<T>::List(const List<T> &oldList)
{
    head = NULL;
    Node<T> *el = oldList.head;
    while (el != NULL)
    {
        addElement(el->getVal(), el->getColNum());
        el = el->getNext();
    }
}

/* Assignment operator overload */
template <class T>
List<T> &List<T>::operator=(const List<T> &oldList)
{
    if (head != NULL)
        clear();
    Node<T> *el = oldList.head;
    while (el != NULL)
    {
        addElement(el->getVal(), el->getColNum());
        el = el->getNext();
    }
    return *this;
}
template <class T>
List<T> List<T>::operator+(const List<T> &other)  
{
    List<T> result;
    Node<T> *p1 = head;
    Node<T> *p2 = other.head;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->getColNum() == p2->getColNum())
        {
            result.addElement(p1->getVal() + p2->getVal(), p1->getColNum());
            p1 = p1->getNext();
            p2 = p2->getNext();
        }
        else if (p1->getColNum() > p2->getColNum())
        {
            result.addElement(p2->getVal(), p2->getColNum());
            p2 = p2->getNext();
        }
        else if (p1->getColNum() < p2->getColNum())
        {
            result.addElement(p1->getVal(), p1->getColNum());
            p1 = p1->getNext();
        }
    }
    while (p1 != NULL && p2 == NULL)
    {
        result.addElement(p1->getVal(), p1->getColNum());
        p1 = p1->getNext();
    }
    while (p2 != NULL && p1 == NULL)
    {
        result.addElement(p2->getVal(), p2->getColNum());
        p2 = p2->getNext();
    }
    return result;
}

/* Conversion constructor */
template <class T>
List<T>::List(const T *arr, int size)
{
    head = NULL;
    for (int i = 0; i < size; i++)
    {
        addElement(arr[i], i);
    }
}

/* Extraction operator overload.
 * Assumes the extraction operator has been overloeaded for the
 * type used for instantiation
 * */

template <class T>
istream &operator>>(istream &in, List<T> &l)
{
    l.clear();
    T tempNull;

    in >> tempNull; // get the temp null

    T val;          // val of input
    int column = 0; // col num
    string rowInput;
    getline(in, rowInput);
    stringstream ss(rowInput);

    while (ss >> val) // continue as long as input comes in
    {
        if (val != tempNull)
        {
            l.addElement(val, column); // add element if val doesnt equal temp null
        }
        column++; // increment column
    }
    return in;
}

template <class T>
Node<T> *List<T>::getHead() const
{
    return head; // return head
}
