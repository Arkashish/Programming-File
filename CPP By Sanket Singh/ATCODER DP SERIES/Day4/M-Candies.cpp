//problem link - https://atcoder.jp/contests/dp/tasks/dp_m
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
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
ll dp[105][100005];
ll candies(vector<int> &arr, ll n, ll k)
{
    for(ll j=0;j<=k;j++)
    {
        dp[1][j] = (j>arr[1]) ? 0:1; 
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)
            dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = (mod + dp[i][j-1] + dp[i-1][j] - ((j-arr[i]-1>=0)?dp[i-1][j-arr[i]-1]:0))%mod;
            }
        }
    }
    return dp[n][k];
}
int main()
{
    clock_t begin = clock();
    file_io();
    memset(dp,0,sizeof(dp));
    ll n,k;
    cin>>n>>k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<candies(arr,n,k)<<"\n";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}