/*  HEAP is a type  of Data strcture which works with 2 condition (Complete Binary Tree + min or max heap properties)
{
    MIN Heap -> min heapify in CBT is like all the root(parent) node values will be less then from both left and right nods
    MAX Heap -> max heapify in CBT is like all the root(parent) node values will be grater then from both left and right nodes
}
    CBT - means (complete binary tree ----> means all level will be completely filled expect the last level(could be or could not be)

    Visualisation -> we will visualise the heap in form of complete binary tree but
    Implementation -> will be based on the array data structure with index starting from 1


    Rules of formulas:
    if we want to find the position of left child of any root node - 2*i & for right child  2*i+1;
    if we want find the parent node index of any child the just (i/2);
 */

#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int index;

    Heap(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        index = 0;
    }

    void printHeap()
    {
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void insert(int val)
    {
        if (index >= capacity)
        {
            cout << "The heap is overflow" << endl;
        }

        index++;
        arr[index] = val;
        int currentIndex = index;
        while (currentIndex > 1)
        {
            int paraentIndex = currentIndex / 2;
            if (arr[currentIndex] > arr[paraentIndex])
            {
                swap(arr[currentIndex], arr[paraentIndex]);
                currentIndex = paraentIndex;
            }
            else
                break;
        }
    }

    void heapfiy(int *arr, int n, int currentIndex)
    {
        int i = currentIndex;
        int largestIndex = i; // taking to store the index of largest index from root , left , right
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        // check with left child

        if (leftIndex < n && arr[leftIndex] > arr[largestIndex])
        {
            largestIndex = leftIndex;
        }

        if (rightIndex < n && arr[rightIndex] > arr[largestIndex])
        {
            largestIndex = rightIndex;
        }

        if (largestIndex != i)
        {
            swap(arr[largestIndex], arr[i]);
            i = largestIndex;
            heapfiy(arr, n, i);
        }
    }

    void deleteFromHeap()
    {
        // in heap we will delete the root node only
        /* Algorithm --> replace the root node will from the last node of the heap
           then remove the element by from the heap and whatever the value you have replace at root ,
           according to the defination called the minHeapify and maxHeapif */

        //--> time complexity will be O(logn) and

        // 1st - swap the first to last element in the heap
        swap(arr[1], arr[index]);

        // 2nd - reduce the size
        arr[index] = 0;
        index--;

        // 3rd - call the heapfiy the function
        heapfiy(arr, index, 1);
    }
};

int main()
{
    Heap pq(10);
    pq.insert(10); //-->hight travel divide/2 and as its CBT so heap will take insertion of O(logn)
    pq.insert(20);
    pq.insert(30);
    pq.insert(40);
    pq.insert(50);
    pq.printHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();

    return 0;
}