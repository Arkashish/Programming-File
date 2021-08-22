

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &ar,int n)
{
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[ar[i]]++;
    }
    for (int i = 0; i < ar.size(); i++)
    {
        if(mp[ar[i]]>1)
            return ar[i];
    }
    return -1; 
}
int main()
{
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<find(ar,n)<<endl;
}