
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
    ListNode *reversell(ListNode *head)
    {

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextptr = NULL;

        while (curr != NULL)
        {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        head = prev;
        return head;
    }
    ListNode *reversellrecursively(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return head;

        ListNode *p = reversellrecursively(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};