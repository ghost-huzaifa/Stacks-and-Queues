//Stack.cpp

#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
Stack<T> :: Stack()                         //Constructor
{
    arr = new T[10];
    topIndex = -1;
    maxIndex = 9;
}

template <class T>
Stack<T> :: Stack(int size)                 //Parametrized Constructor
{
    arr = new T[size];
    topIndex = -1;
    maxIndex = size - 1;
}

template <class T>
Stack<T> :: Stack(const Stack& other)        //Copy Constructor
{
    if (other.empty())
        return;

    topIndex = -1;
    maxIndex = other.maxIndex;
    arr = new T[maxIndex + 1];

    for (int i = 0; i <= maxIndex; i++)
    {
        this->arr[i] = other.arr[i];
    }
}

template <class T>
Stack<T> :: ~Stack()               //Destructor
{
    delete arr;
}

template <class T>
bool Stack<T> :: empty() const             //Checks if Stack is empty
{
    return topIndex == -1;
}

template <class T>
bool Stack<T> :: full() const              //Checks if Stack is full
{
    return topIndex == maxIndex;
}

template <class T>
void Stack<T> :: push(const T data)        //Push data at top
{
    if (full())
        cout << "Cannot push data... Stack is full" << endl;
    else{
        arr[++topIndex] = data;
    }
}

template <class T>
T Stack<T> :: pop()                        //Pop data from top
{
    if (empty()){
        cout << "Cannot pop data.. Stack is empty" << endl;
        return NULL;
    }
    else
        return arr[topIndex--];
}

template <class T>
T Stack<T> :: top() const                  //Get top element
{
    if (empty()){
        cout << "No top element... Stack is empty" << endl;
        return NULL;
    }
    else
        return arr[topIndex];
}

template <class T>
void Stack<T> :: print()                   //Print the Stack
{
    if (empty())
        cout << "Stack is empty" << endl;
    else{
            cout << "Data in Stack :" << endl;
        for (int i = topIndex; i >= 0; i--){
            cout << "|\t" << arr[i] << "\t|" << endl;
        }
        cout << " ---------------- " << endl;

    }
}
