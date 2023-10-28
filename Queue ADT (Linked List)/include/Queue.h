#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
using namespace std;
struct Node{
    double data;
    Node* next;
};
typedef Node* NodePtr;

class Queue{
public:
    Queue();
    Queue(Queue& other);
    ~Queue();

    bool empty();
    void enqueue(double x);
    double dequeue();

    void print();
private:
    int counter;
    NodePtr front;
    NodePtr rear;
};
#endif // QUEUE_H_INCLUDED
