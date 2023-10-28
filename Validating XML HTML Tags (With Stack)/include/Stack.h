//Stack.h

#ifndef STACK_H
#define STACK_H
#include "List.h"

template <class T>
class Stack : public List<T>
{
    public:
        // Constructors
        Stack();                         //Default Constructor

        // Destructor
        virtual ~Stack();

        // Check Functions
        bool empty() const;             //Checks if Stack is empty

        // Stack Operational Functions
        void push(const T data);        //Push data at top
        T pop();                        //Pop data from top

        // Miscellaneous Functions
        T top() const;                  //Get top element
        void print();
};

#endif // STACK_H
