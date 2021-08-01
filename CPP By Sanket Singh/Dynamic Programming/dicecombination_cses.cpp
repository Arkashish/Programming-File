
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
ll dice(ll n)
{
    vector<ll> dp(n+1,0);
    dp[0]=dp[1]=1;
    for(ll i=2;i<=n;i++)
    {
        for(ll j=1;j<=6;j++)
        {
            if(j>i)
            continue;

            // dp[i] = ((dp[i]%mod) + (dp[i-j]%mod))%mod ;
            dp[i] = ((dp[i]%mod) + (dp[i-j]%mod))%mod ;
        }
    }
    return dp[n];

}
int main()
{
    ll n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<dice(n)<<"\n";
}