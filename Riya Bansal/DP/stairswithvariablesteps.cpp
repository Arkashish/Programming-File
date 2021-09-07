//date of prob 8th june 2021
#include <bits/stdc++.h>
using namespace std;

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
int numberofjumps(vector<int> &dp,int ar[],int n)
{
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=ar[i] and (i+j)<dp.size();j++)
        {
            dp[i] += dp[i+j];
        }
    }
    return dp[0];
}
int main(int argc, char* argv[])
{
    clock_t begin = clock();
    file_io();
    
    int n;
    cin>>n;
    vector<int> dp(n+1);
    int ar[] = {3,3,0,2,2,3};
    cout<<numberofjumps(dp,ar,n)<<"\n";

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
    return 0;
}