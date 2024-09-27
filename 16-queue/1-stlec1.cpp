#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> &q)
{
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return;
}
int main()
{
    // creation of queue
    queue<int> q;

    // inserting the element in the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // front element
    cout << q.front() << endl;
    // size of the queus
    cout << q.size() << endl;
    // check queue is empty
    cout << q.empty() << endl;
    // queue rear element
    cout << q.back() << endl;

    print(q);

    // doubly ended queue

    return 0;
}