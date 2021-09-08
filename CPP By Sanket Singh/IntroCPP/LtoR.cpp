
//date - 20/09/21
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        v[l]++;
        if(r<n) 
        v[r+1]--;
    }
    for(int i=1;i<n;i++)
    {
        v[i] = v[i]+v[i-1];
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i] <<" ";
    }
    cout<<"\n";
    
}