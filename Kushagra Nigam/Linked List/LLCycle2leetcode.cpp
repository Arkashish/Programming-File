
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
            return NULL;

        ListNode *ptr = head;
        map<ListNode *, int> mp;

        while (ptr)
        {
            if (mp.find(ptr) != mp.end())
                return ptr;

            mp[ptr] = 1;
            ptr = ptr->next;
        }
        return NULL;
    }
};