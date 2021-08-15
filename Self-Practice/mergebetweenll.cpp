

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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *tmp = list1;
        int c=1;
        if(a>b)
            return NULL;
        while(c<a)
        {
           
            tmp=tmp->next;
             c++;
            
        }
        ListNode *cp = tmp;
        while(a!=b)
        {
            tmp=tmp->next;
            a++;
        }
        tmp=tmp->next->next;
        cp->next = list2;
        while(list2->next!=NULL)
        {
            list2=list2->next;
        }
        list2->next=tmp;
        return list1;
    }
};