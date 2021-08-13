
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
    int getDecimalValue(ListNode* head) {
        ListNode* tmp = head;
        stack<int> st;
        while(tmp!=NULL)
        {
            st.push(tmp->val);
            tmp = tmp->next;
        }
        int n = st.size();
        int sum=0;
        int i=0;
            while( i<n)
            {
                sum+=((st.top())*(pow(2,(i))));
                st.pop();
                i++;
            }
        return sum;
    }
};