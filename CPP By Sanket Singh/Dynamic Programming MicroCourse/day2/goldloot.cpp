
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(vector<int> &ar)
{
    vector<ll> dp(ar.size());
    dp[0] = ar[0];
    dp[1] = max(ar[0], ar[1]);
    if (ar.size() == 0)
        return 0;
    if (ar.size() == 1)
        return dp[0];
    if (ar.size() == 2)
        return dp[1];

    
    for (int i = 2; i < ar.size(); i++)
    {
        dp[i] = max(dp[i - 1], ar[i] + dp[i - 2]);
    }
    for(int i=0;i<dp.size();i++)
    {cout<<dp[i]<<" ";}
    cout<<"\n";
    return dp[ar.size()-1];
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
    cout<<f(ar)<<"\n";
}