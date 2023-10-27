//Stack.h

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
    public:
        // Constructors
        Stack();                         //Default Constructor
        Stack(int size);                //Parametrized Constructor
        Stack(const Stack& other);      //Copy Constructor

        // Destructor
        virtual ~Stack();

        // Check Functions
        bool empty() const;             //Checks if Stack is empty
        bool full() const;              //Checks if Stack is full

        // Stack Operational Functions
        void push(const T data);        //Push data at top
        T pop();                        //Pop data from top

        // Miscellaneous Functions
        T top() const;                  //Get top element
        void print();                   //Print the Stack

    private:
        int topIndex;
        int maxIndex;
        T *arr;
};

#endif // STACK_H
