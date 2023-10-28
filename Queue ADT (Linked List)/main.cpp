#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    //Creating an Instance of Queue
    Queue L;
    if(L.empty()) //Checking if the Queue is empty or not
    {
        /*if the queue is empty, the empty() function
        will return a boolean value and it will be check by
        if statement*/
        cout << "L Queue is empty." << endl;
    }
    //Adding elements to the Queue
    L.enqueue(10.5);
    L.enqueue(50);
    L.enqueue(30);
    L.enqueue(15);
    L.enqueue(26.5);
    L.enqueue(4);

    //print() function will print all the element of the Queue.
    L.print();
    //Following is the Copy Constructor that will
    //copy all the contents of the existing queue
    //into a new one.
    Queue N(L);
    cout << "Elements of N Queue" << endl;
    N.print();
    cout << "Dequeue from L Queue" << endl;
    //An element from the front of the queue is returned as
    //queue works on First in First Out formula
    cout << "\tDequeued Element:\t" << L.dequeue() << endl;
    L.print();
    return 0;
}
