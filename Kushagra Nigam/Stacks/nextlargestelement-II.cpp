#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
	{
	    cin>>ar[i];
	}
	int ans[n];
    int max=INT_MIN;
    int pos = 0;
// 	ans[n-1]=-1;
	stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if(max<ar[i]){
        max = ar[i];
        pos = i;
        }
    }
    
	for(int i=n-1;i>=0;i--)
	{
	    
	    while(!st.empty() and ar[i]>st.top())
	        st.pop();
	    if(st.empty())
	        ans[i]=-1;
	    else
	        ans[i] = st.top();
	        
	    st.push(ar[i]);
	}
    for(int i=n-1;i>pos;i--)
	{
	    
	    while(!st.empty() and ar[i]>=st.top())
	        st.pop();
	    if(st.empty())
	        ans[i]=-1;
	    else
	        ans[i] = st.top();
	        
	    st.push(ar[i]);
	}

    //cout<<st.top()<<endl;
	for(int i=0;i<n;i++)
	{
	    cout<<ans[i]<<" ";
	}
	return 0;
}

/*
Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

//Vector version for leetcode
/*class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& ar) {
        
        int max=INT_MIN;
        int pos = 0;
        int n = ar.size();
        int ans[n];
	    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if(max<ar[i]){
        max = ar[i];
        pos = i;
        }
    }
    
	for(int i=n-1;i>=0;i--)
	{
	    
	    while(!st.empty() and ar[i]>=st.top())
	        st.pop();
	    if(st.empty())
	        ans[i]=-1;
	    else
	        ans[i] = st.top();
	        
	    st.push(ar[i]);
	}
    for(int i=n-1;i>pos;i--)
	{
	    
	    while(!st.empty() and ar[i]>=st.top())
	        st.pop();
	    if(st.empty())
	        ans[i]=-1;
	    else
	        ans[i] = st.top();
	        
	    st.push(ar[i]);
	}
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(ans[i]);
        }
        return v;
    }
};
*/