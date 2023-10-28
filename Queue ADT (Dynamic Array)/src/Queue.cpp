#include <iostream>
#include "Queue.h"
//Default Constructor for the Queue
Queue::Queue(int size){
    //setting value of front and rear
    front = 0;
    rear = -1;
    maxSize = size;
    counter = 0;
    values = new double[maxSize];
}
//Copy Constructor for copying a queue to the a new one
Queue::Queue(Queue& other) {
    counter = 0;
    front = 0;
    rear = -1;
    maxSize = other.maxSize;
    values = new double[maxSize];
    for(int i = 0; i < other.counter; i++)
    {
        enqueue(other.values[i]);
    }
}
bool Queue::full()
{
    if(counter > maxSize)
    return true;
    else return false;
}
//This function will return a boolean based on the condition
bool Queue::empty()
{
    if(counter)
        return false;
    else return true;
}

//Enqueue function to add new elements to the rear
void Queue::enqueue(double x)
{
    if(full())
    {
        cout << "Queue is Full." << endl;
        exit(1);
    }
    else
    {
        rear = (rear + 1) % maxSize;
        values[rear] = x;
        counter++;
    }
}
//Dequeue function to return a value from the Queue
double Queue::dequeue()
{
  double data;
  //Getting value from the Front and putting it in the data variable.
  data = values[front];
  //Changing the Front
  front = (front + 1) % maxSize;
  //Decrementing the Counter for Queue
  counter--;
  return data;
}

//Print function will print all the values present in the queue.
void Queue::print()
{
    cout << "front -->";
    for (int i = 0; i < counter; i++) {
        if (i == 0) cout << "\t";
    else cout << "\t\t";
        cout << values[(front + i) % maxSize];
    if (i != counter - 1)
        cout << endl;
    else
        cout << "\t<-- rear" << endl;
}

}
//Destructor for the Queue
//It will delete all the nodes freeing all the memory
//and emptying the heap.
Queue::~Queue()
{
    delete values;

}
