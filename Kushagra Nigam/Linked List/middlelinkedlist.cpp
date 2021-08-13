
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* start = head;
        ListNode* fin = start;
        ListNode* tmp = start;
        int c=0;
        while(tmp!=NULL){
             c++;
            tmp=tmp->next;
        }
           
        if(c%2==0){
        while(fin!=NULL)
        {
            start = start->next;
            fin=fin->next->next;
        }
        return start;
        }
        else{
          while(fin->next!=NULL)
        {
            start = start->next;
            fin=fin->next->next;
        }
        return start;  
        }
    }
};