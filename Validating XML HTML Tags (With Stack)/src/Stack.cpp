//Stack.cpp

#include "Stack.h"
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
Stack<T> :: Stack()                         //Constructor
{
    //List will be created
}

template <class T>
Stack<T> :: ~Stack()               //Destructor
{
    //List will be deleted
}

template <class T>
bool Stack<T> :: empty() const             //Checks if Stack is empty
{
    return List<T>::empty();
}

template <class T>
void Stack<T> :: push(const T data)        //Push data at top
{
    List<T>::addHead(data);
}

template <class T>
T Stack<T> :: pop()                        //Pop data from top
{
    if (empty()){
        cout << "Cannot pop data.. Stack is empty" << endl;
        return NULL;
    }
    else{
        T headElement = List<T>::headElement();
        List<T>::delHead();
        return headElement;
    }
}

template <class T>
T Stack<T> :: top() const                  //Get top element
{
    if (empty()){
        cout << "No top element... Stack is empty" << endl;
        return NULL;
    }
    else
        return List<T>::headElement();
}

template <class T>
void Stack<T> :: print()                   //Print the Stack
{
    if (empty())
        cout << "Stack is empty" << endl;
    else{
            cout << "Data in Stack :" << endl;
        List<T>::print();
    }
}
