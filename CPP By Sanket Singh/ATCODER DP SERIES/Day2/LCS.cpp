
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

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

    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
    vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans = dp[n][m];
    string str(ans,' ');
    int i=n,j=m;
    while(i>0 and j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            str[ans-1]=s1[i-1];
            i--,j--;ans--;
        }
        //now for upwad checlk
        else if (dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<str<<"\n";
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
}