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

// buildheap is a function that will take array and convert to heap
// we have to call heap from n/2 to 1 as leaf node will be itself heapfied as it a single node
// we will travel from n/2 only beacuse we will consider that from the n/2 nodes we are heapfing each node and also we are
// leaving the leaf node so to maintain that we need to start from n/2 last node
//  so time complexity --- O(n);
void buildHeap(int *arr, int n)
{
    for (int i = n / 2; i > 0; i--)
        heapfiy(arr, n, i);
}

void HeapSort(int *arr, int n)
{
    int end = n - 1;
    while (end > 1)
    {
        swap(arr[1], arr[end]);
        heapfiy(arr, end, 1);
        for (int i = 1; i < n; i++)
            cout << arr[i] << " ";
        end--;

        cout << endl;
    }
}

int KthLargestElement(int *arr, int n, int k)
{
    int end = n - 1;
    while (end >= n - k + 1)
    {
        swap(arr[1], arr[end]);
        heapfiy(arr, end, 1);
        end--;

        cout << endl;
    }

    return arr[1];
}
int main()
{

    int arr[] = {-1, 30, 20, 40, 10, 50};
    int n = 6;
    buildHeap(arr, n);

    cout << "Printing the heap " << endl;
    for (int i = 1; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // calling the heap sort
    // HeapSort(arr, n);

    cout << "Printing the heapsort" << endl;
    for (int i = 1; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int ans = KthLargestElement(arr, n, 2);
    cout << ans;

    return 0;
}