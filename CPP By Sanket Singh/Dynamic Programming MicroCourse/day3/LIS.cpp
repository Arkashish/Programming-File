
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll lis(vector<ll> &ar,ll n)
{
    vector<ll> dp(n,1);

    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(ar[i]>ar[j])
                dp[i] = max(dp[i],1+dp[j]);
        }
    }
    ll result = INT_MIN;
    for (ll i = 0; i < dp.size(); i++)
    {
        result = max(result,dp[i]);
    }
    // cout<<result<<"\n";
    return result;
    
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    cout<<lis(v,n)<<"\n";
}