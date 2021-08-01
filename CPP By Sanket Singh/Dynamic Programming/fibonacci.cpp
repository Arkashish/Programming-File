
#include<bits/stdc++.h>
using namespace std;

int fib(vector<int> &dp,int n)
{
    if(n==0 || n==1)
    return n;
    if(dp[n]!=-1)
    return dp[n];

    int ans = fib(dp,n-1) + fib(dp,n-2);
    dp[n]=  ans;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(dp,n)<<endl;
}