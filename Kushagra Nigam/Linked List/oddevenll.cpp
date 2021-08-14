
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
    ListNode *oddeven(ListNode *head)
    {
        ListNode *ptr = head;
        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        int count = 1;
        ListNode *p=odd,*q=even;

        while(ptr!=NULL)
        {
            if(count%2!=0)
            {
                p->next = ptr;
                p = p->next;
            }
            else
            {
                q->next = ptr;
                q = q->next;
            }
            count++;
            ptr = ptr->next;
        }

        p->next = even->next;
        q->next = NULL;
        return odd->next;
    }
};