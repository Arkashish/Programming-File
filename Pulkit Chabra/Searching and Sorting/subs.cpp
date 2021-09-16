//https://www.codechef.com/UAPRAC/problems/SUBS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int &i: v)
        {
            cin>>i;
        }
        sort(v.begin(),v.end());
        int ans = INT_MAX;
        for(int i=0;i+k-1<n;i++)
        {
            ans = min(ans,v[i+k-1]-v[i]);
        }
        cout<<ans<<"\n";
    }
    
}