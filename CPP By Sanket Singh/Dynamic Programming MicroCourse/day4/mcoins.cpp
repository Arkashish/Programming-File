
//problem link - https://unacademy.com/class/problem-solving-on-dynamic-programming-4/A325QITE

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//recursive approach
int f(int n,int k,int l,vector<ll> &dp)
{
    if(n==0) return 0;
    if(n==1 or n==k or n==l)
        return dp[n] = 1;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = 1 -( f(n-1,k,l,dp) and ((n-k>=0)?f(n-k,k,l,dp):1) and (n-l>=0)?f(n-l,k,l,dp):1 ) ;
}
int main()
{
    ll k,l,m;
    cin>>k>>l>>m;
    vector<ll> dp1(1000005,-1); //initially losing state
    f(10000,k,l,dp1);
    vector<ll> dp(1000005,0); //initially losing state
    dp[1] = dp[k] = dp[l] = 1;//winning state
    for(int i= 0 ; i<1000005;i++)
    {
        dp[i] = dp[i-1] and ((i-k>=0)? dp[i-k]:1) and ((i-l>=0)? dp[i-l]:1);
        dp[i] = 1 - dp[i]; //calculating the not
    }

    while(m--){
        ll x;
        cin>>x;
        if(dp1[x]){
            cout<<"A";
        }
        else
        {
            cout<<"B";
        }
        
    }

}