#include <iostream>

using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int size;
    int rear;

    Queue(int capacity)
    {
        arr = new int[capacity];
    }
};

int main()
{

    return 0;
}