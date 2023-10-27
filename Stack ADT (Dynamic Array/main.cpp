//main.cpp

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> s1(20);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.print();
    s1.pop();
    s1.pop();
    int temp = s1.pop();
    s1.print();
    s1.push(60);
    s1.push(70);
    s1.push(80);
    s1.push(90);
    s1.push(100);
    s1.push(temp);
    s1.print();
    return 0;
}
