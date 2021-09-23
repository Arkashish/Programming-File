#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
void file_io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll dp[22][1<<22];
ll matching(vector<vector<ll>> &compat,int i,int mask,int n)
{
    if(i==n+1)
    {
        if(mask==0) return 1;
        return 0;
    }
    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }
    ll ans = 0;
    for(ll w=0;w<n;w++)
    {
        bool available = (((1<<w)&(mask))==0)?0:1;
        if(available and compat[i][w+1]==1)
        ans=((ans%mod)+(matching(compat,i+1, mask^(1<<w),n)%mod))%mod;
    }
    dp[i][mask] = ans;
}
int main()
{
    clock_t begin = clock();
    file_io();
    ll n;
    cin>>n;
    vector<vector<ll>> compat(n+1,vector<ll>(n+1));
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>compat[i][j];
        }
    }
    cout<<matching(compat,1,((1<<n)-1),n);
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}