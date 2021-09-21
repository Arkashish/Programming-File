

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 100000009
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


int main()
{
    clock_t begin = clock();
    file_io();
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            grid[i][j] = s[j-1];
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    dp[n][m]=1;

    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(i==n and j==m)
            {
                continue;
            }
            if(grid[i][j]=='#')
            {
                dp[i][j]=0;
                continue;
            }
            dp[i][j] = (((i==n)?0:dp[i+1][j])%mod + ((j==m)?0:dp[i][j+1])%mod)%mod;
        }
    }
    cout<<dp[1][1]<<"\n";
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
}