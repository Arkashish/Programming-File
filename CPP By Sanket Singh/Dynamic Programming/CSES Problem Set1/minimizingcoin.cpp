
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,x;
    cin>>n>>x;
    ll coin[n];
    for (int i = 0; i < n; i++)
    {
        cin>>coin[i];
    }
    
    vector<ll> dp(x+1, INT_MAX);

    dp[0]=0;
    for(ll i=1;i<=x;i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if(coin[j]>i)
            continue;

            // dp[i] = min(dp[i],1+dp[i-coint[j]]);
            dp[i] = min(dp[i],1+dp[i-coin[j]]);
        }
    }
    if(dp[x]==INT_MAX)
    cout<<"-1\n";
    else
    cout<<dp[x];
}