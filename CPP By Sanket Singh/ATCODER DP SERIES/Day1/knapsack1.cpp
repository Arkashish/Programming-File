
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,w;
    cin>>n>>w;
    vector<ll> wt(n,0);
    vector<ll> val(n,0);
    vector<ll> d1(w+1,0);
    vector<ll> d2(w+1,0);
    for(ll i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i]>j)
            {
                d2[j] = d1[j];
            }
            else{
                d2[j] = max({d2[j],d1[j],val[i]+d1[j-wt[i]]}); 
            }
        }
        d2.swap(d1);
        d2.clear();
    }
    cout<<d1[w]<<"\n";

}