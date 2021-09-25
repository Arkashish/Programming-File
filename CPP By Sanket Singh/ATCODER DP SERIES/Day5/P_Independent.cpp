#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define endl "\n"
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
vector<int> tree[100005]; //array of vector
ll dp[100005][2];
ll independentset(int node,int parent,int c)//here c can be considered both as color or constraint
{
    if(dp[node][c]!=-1)
        return dp[node][c];
    ll ans = 0;
    ll w0=1;
    for (auto child : tree[node])
    {
        if (child!=parent)
        {
            w0 = ((w0%mod)*(independentset(child,node,0)%mod))%mod;
        }
    }
    ans +=w0;
    if(not c)
    {
        ll w1=1;
    for (auto child : tree[node])
    {
        if (child!=parent)
        {
            w1 = ((w1%mod)*(independentset(child,node,1)%mod))%mod;
        }
    }
    ans = (ans%mod + w1%mod)%mod;
    }
    return dp[node][c] = ans;
}
int main()
{
    clock_t begin = clock();
    file_io();
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cout<<independentset(1,-1,0)<<endl;
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}