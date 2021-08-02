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
// 	ans[n-1]=-1;
	stack<int> st;
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
	for(int i=0;i<n;i++)
	{
	    cout<<ans[i]<<" ";
	}
	return 0;
}

/*
7
2 3 1 7 6 4 5
*/