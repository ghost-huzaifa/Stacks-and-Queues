#include <iostream>
#include "Queue.h"
//Default Constructor for the Queue
Queue::Queue(){
    //setting value of front and rear
    front = rear = NULL;
    counter = 0;
}
//Copy Constructor for copying a queue to the a new one
Queue::Queue(Queue& other) {
     front = rear = NULL;
        counter = 0;
        //A check to verify whether the original queue is empty or not
    if (other.empty()) {

        cout << "Original Queue is empty." << endl;
    } else {
        //Getting the value of the front pointer of original queue
        NodePtr otherCurrent = other.front;
        while(otherCurrent != NULL)
        {
            //Adding data to the new queue
            enqueue(otherCurrent->data);
            otherCurrent = otherCurrent->next;
        }
        //Updating the value of the new counter
        counter = other.counter;
    }
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
    NodePtr newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if(empty())
    {
        front = newNode;
    }
    else{
        rear->next = newNode;
    }
    rear = newNode;
    counter++;
}
//Dequeue function to return a value from the Queue
double Queue::dequeue()
{
  double data;
  if(empty())
  {
    cout << "Error: Queue is empty" << endl;
    return 1;
  }
  data = front->data;
  //Saving the value of front so that it won't be
  //lost when front is deleted.
  NodePtr tempPtr = front->next;
  delete front;
  front = tempPtr;
  counter--;
  return data;
}

//Print function will print all the values present in the queue.
void Queue::print()
{
    NodePtr currentPtr = front;
    if(empty())
    {
        cout << "Queue is empty." << endl;
        exit(1);
    }
    else
    {
        cout << "front -->";
        for (int i = 0; i < counter; i++)
            {
                if (i == 0) cout << "\t";
                else cout << "\t\t";
                    cout << currentPtr->data;
                if (i != counter - 1)
                    cout << endl;
                else
                    cout << "\t<-- rear" << endl;
                currentPtr = currentPtr->next;
            }
    }


}
//Destructor for the Queue
//It will delete all the nodes freeing all the memory
//and emptying the heap.
Queue::~Queue()
{
    Node* currentPtr = front;
    for(int i = 0; i < counter; i++)
    {
        Node* tempPtr = currentPtr->next;
        delete currentPtr;
        currentPtr = tempPtr;
    }

}
