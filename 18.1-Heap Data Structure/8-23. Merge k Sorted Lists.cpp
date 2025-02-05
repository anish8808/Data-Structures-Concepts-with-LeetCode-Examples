#include <bits/stdc++.h>

using namespace std;

// ListNode *mergeKLists(vector<ListNode *> &lists)
// {
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     for (ListNode *i : lists)
//     {
//         ListNode *head = i;
//         while (head != NULL)
//         {
//             minHeap.push(head->val);
//             head = head->next;
//         }
//     }
//     ListNode *head = NULL;
//     if (minHeap.empty())
//         return head;

//     int val = minHeap.top();
//     head = new ListNode(val);
//     ListNode *ans = head;
//     minHeap.pop();
//     while (!minHeap.empty())
//     {
//         int val = minHeap.top();
//         ListNode *newNode = new ListNode(val);
//         head->next = newNode;
//         head = newNode;
//         minHeap.pop();
//     }

//     return ans;
// }

int main()
{
    vector<int> nums{1, 4, 5, 22, 2, 3};
    // int ans1 = mergeKLists(nums);

    // cout << ans1 << " " << endl;

    return 0;
}