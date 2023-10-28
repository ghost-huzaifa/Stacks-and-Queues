#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
using namespace std;

class Queue{
public:
    Queue(int size = 10);
    Queue(Queue& other);
    ~Queue();

    bool empty();
    bool full();
    void enqueue(double x);
    double dequeue();

    void print();
private:
    double* values;
    int front;
    int rear;
    int maxSize;
    int counter;
};
#endif // QUEUE_H_INCLUDED
