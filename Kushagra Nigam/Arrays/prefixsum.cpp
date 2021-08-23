
//Similar to problem : https://www.codechef.com/problems/GOLDTRIP
#include <bits/stdc++.h>
using namespace std;

int prefixsum(vector<int> v, int n,int l,int r)
{
    vector<int> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1]+v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    return prefix[r]-prefix[l-1];
}

int prefixsum1(vector<int> v, int n,int l,int r) //this function returns the sum excluding the range
{
    vector<int> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1]+v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    return prefix[n-1] -(prefix[r]-prefix[l-1]);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int l,r;
    cin>>l>>r;
    cout<<prefixsum(v,n,l,r)<<endl;
    cout<<prefixsum1(v,n,l,r)<<endl;

}