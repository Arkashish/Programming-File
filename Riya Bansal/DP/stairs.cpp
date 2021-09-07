
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

int stairsrecursive(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    

    return stairsrecursive(n-1)+stairsrecursive(n-2)+stairsrecursive(n-3);

}

int stairsdp(int n,vector<int> &dp) //memoization
{
    if(n==0) return 1;
    if(n<0) return 0;
    
    if(dp[n]>0)
        return dp[n];
    
    
    return dp[n]=stairsrecursive(n-1)+stairsrecursive(n-2)+stairsrecursive(n-3);

}

int stairstab(int n)//by method of tabulation
{
    int dp[n+1];
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        if(i==1) dp[i] = dp[i-1];
        else if(i==2) dp[i] = dp[i-1] + dp[i-2];
        else dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
        
    }
    return dp[n];

}
int main(int argc, char* argv[])
{
    clock_t begin = clock();
    file_io();
    
    int n;
    cin>>n;
    vector<int> dp(n+1);
    cout<<stairsdp(n,dp)<<"\n";
    cout<<stairsrecursive(n)<<"\n";
    cout<<stairstab(n)<<"\n";


    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
    return 0;
}