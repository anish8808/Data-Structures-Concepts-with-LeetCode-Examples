#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // create deque
    deque<int> deq;

    // insertion

    // push in front
    deq.push_front(10);
    deq.push_front(20);
    deq.push_front(30);
    deq.push_front(40);

    // push bach
    deq.push_back(100);
    deq.push_back(110);

    cout << deq.size() << endl;
    cout << deq.front() << endl;
    cout << deq.back() << endl;

    // removal

    // delete from the front
    deq.pop_front();
    // delete from the back
    deq.pop_back();
    cout << deq.size() << endl;
    cout << deq.front() << endl;
    cout << deq.back() << endl;

    return 0;
}