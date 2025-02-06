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

//---->optimized solution

/*

    class Solution {
public:
    class compare{
        public:
        bool operator()(ListNode* a , ListNode* b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare>pq;
        for(ListNode* i :lists)
        {
            if(i!=NULL)
                pq.push(i);
        }

        if (pq.empty()) {
            return nullptr;
        }

        ListNode* temp =  new ListNode(-1);
        ListNode* ans = temp ;
        while(!pq.empty())
        {
            ListNode* head =  pq.top();
            pq.pop();
            temp->next = head ;
            temp = head;
            if(head->next!=NULL)
            {
                pq.push(head->next);
            }
        }

        return ans->next ;
    }
};
*/
int main()
{
    vector<int> nums{1, 4, 5, 22, 2, 3};
    // int ans1 = mergeKLists(nums);

    // cout << ans1 << " " << endl;

    return 0;
}