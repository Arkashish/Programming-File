
#include <bits/stdc++.h>
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
double dp[3005][3005]; //->dp[i][j] prob to get atleast j heads in i calls
double coins(vector<double> &ar,int i,int x)
{
    if(x==0)
    return 1;
    if(i==0 )
    return 0;
    if(dp[i][x]>-.9)
    return dp[i][x];
    return dp[i][x] = ar[i]*coins(ar,i-1,x-1) + (1-ar[i])*coins(ar,i-1,x);
}
int main()
{
    clock_t begin = clock();
    file_io();
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<double> ar(n+1);
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    cout<<fixed<<setprecision(10)<<coins(ar,n,(n+1)/2);
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}