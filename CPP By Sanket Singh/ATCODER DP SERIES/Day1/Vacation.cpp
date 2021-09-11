//problem link - https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9

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

int main(int argc, char *argv[])
{
    clock_t begin = clock();
    file_io();
    ll n;
    cin>>n;
    vector<vector<ll>> dp(3,vector<ll>(n,0));
    ll a,b,c;
    cin>>a>>b>>c;
    dp[0][0] = a; //base case1
    dp[1][0] = b; //base case2
    dp[2][0] = c; //base case 3
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>c;
        dp[0][i] = a + max(dp[1][i-1],dp[2][i-1]);
        dp[1][i] = b + max(dp[0][i-1],dp[2][i-1]);
        dp[2][i] = c + max(dp[0][i-1],dp[1][i-1]);
    }
    cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]})<<"\n";
    
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
    return 0;
}