/*
    A priority queue is a type of abstract data structure where each element is associated with a "priority,"
     and elements with higher priority are dequeued (removed) before elements with lower priority.
     If two elements have the same priority,
    they are dequeued in the order they were enqueued (depending on the implementation)


    Use Cases:
        Task scheduling (e.g., OS process scheduling)
        Graph algorithms like Dijkstra's shortest path and Prim's minimum spanning tree
        Event-driven simulations
        Load balancing


    Implementation:
    A priority queue can be implemented using:

    Heap:
        Most common and efficient. For example:
        Min-Heap: Smallest priority element at the root.
        Max-Heap: Largest priority element at the root.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> pq; // by default this will be the max heap
    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(20);
    pq.push(40);

    cout << "This will print the first emelent in queus " << pq.top() << endl;

    // Syntax and creation of the minHeap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(10);
    min_pq.push(50);
    min_pq.push(30);
    min_pq.push(20);
    min_pq.push(40);

    cout << "This will print the first emelent in queus " << min_pq.top() << endl;

    return 0;
}