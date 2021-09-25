#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
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

vvi multiply(vvi &a, vvi &b)
{
    int n = a.size();
    vvi res(n,vector<ll> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] = (res[i][j] + a[i][k]*b[k][j])%mod;
            }
        }
    }
    return res;
}

vvi power_(vvi &mat,ll exp)
{
    if(exp==1)
    {
        return mat;
    }
    vvi res = power_(mat,exp/2);
    vvi ans = multiply(res,res);
    if(exp%2!=0)
    {
        return multiply(ans,mat);
    }
    else
    {
        return ans;
    }
    
}

ll walk(vvi &adj,ll k)
{
    int n = adj.size();
    vvi res = power_(adj,k);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = (ans%mod + res[i][j]%mod)%mod;
        }
    }
    return ans;
}
int main()
{
    clock_t begin = clock();
    file_io();

    ll n,k;
    cin>>n>>k;
    vvi adj(n,vector<ll> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>adj[i][j];
        }
    }
    cout<<walk(adj,k);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}