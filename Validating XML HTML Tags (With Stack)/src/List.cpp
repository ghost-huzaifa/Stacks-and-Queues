//List.cpp

#include <iostream>
#include "List.h"

using namespace std;

template <class T>
List<T>::List()    //Default Constructor
{
    head = NULL;
}

template <class T>
List<T>::~List()   //Destructor
{
    Node<T> *curr = head;
    while (curr!=NULL)
    {
        Node<T> *node = curr;
        curr = curr->next;
        delete(node);
    }
    /*Memory of List is freed one by one
    using delete because it is a linked list*/
}

template <class T>
List<T>::List(const List& other)   //Copy Constructor
{
    head = NULL;
    if (!other.empty())
    {
        Node<T> * curr = other.head;  //Keeps track of current node
        Node<T> * prev = NULL;         //Keeps track of previous node

        while (curr!=NULL)
        {
            // Making and populating Node<T>
            Node<T> * node = new Node<T>;
            node->data = curr->data;
            node->next = NULL;

            //Linking
            if (head == NULL)
                head = node;        //Head points to First Node<T> now
            else
                prev->next = node; //Previous Node<T> points to current node now

            //Traversing the Linked List further
            prev = node;
            curr = curr->next;
        }
    }
}

template <class T>
bool List<T>::empty() const    //Checks if the list is empty
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

template <class T>
T List<T>::headElement() const    //Gets the first element of list
{
    if (empty())
        return NULL;
    else
        return head->data;
}

template <class T>
void List<T>::addHead(T newdata)    //Adds the element at head of list
{
    //Making and populating a new node
    Node<T>* node = new Node<T>;
    node->data = newdata;

    //Placing the node at head
    node->next = head;
    head = node;
}

template <class T>
void List<T>::delHead()    //Delete the head node
{
    if (empty())
        cout << "There is no element in list to remove! " << endl;
    else
    {
        //Storing the node in a temp pointer and then updating the head pointer
        Node<T> *nodeToDelete = head;
        head = head->next;
        delete(nodeToDelete);
    }
}

template <class T>
int List<T>::length() const    //Get no. of elements in list
{
    int size = 0;
    Node<T> *curr = head;
    while (curr != NULL)
    {
        size++;
        curr = curr->next;
    }
    return size;
}

template <class T>
void List<T>::print() const     //Print the list
{
    if (empty())
        cout << "The List is empty!" << endl;
    else
    {
        cout << "List = [ ";

        Node<T> *curr =head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << "]" << endl;
    }
}
