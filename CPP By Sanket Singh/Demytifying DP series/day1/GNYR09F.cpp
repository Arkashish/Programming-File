//Problem link - https://www.spoj.com/problems/GNYR09F/


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

int dp[105][105][2]; //the maximum value of n is 100 and k is order of n s according and k can be either 0 or 1 so we put 2
int f(int n,int k,int first) //recursive approach
{
    if(n==0) return 0;
    if(n==1)
    {
        if(k==0) return 1; // 0
        else return 0;
    }
    int result;
    if(first == 1)
        result = f(n-1,k-1,1) + f(n-1,k,0);
    else
        result = f(n-1,k,1) + f(n-1,k,0);
    
    return result;
}
int f1(int n,int k,int first) //recursive approach
{
    if(n==0) return 0;
    if(n==1)
    {
        if(k==0) return 1; // 0
        else return 0;
    }
    if(dp[n][k][first]!=-1)
        return dp[n][k][first];
    int result;
    if(first == 1)
        result = f1(n-1,k-1,1) + f1(n-1,k,0);
    else
        result = f1(n-1,k,1) + f1(n-1,k,0);
    
    return dp[n][k][first] = result;
}
int main(int argc, char* argv[])
{
    clock_t begin = clock();
    file_io();
    int t;
    cin>>t;
    while (t--)
    {
        int num,n,k;
        cin>>num>>n>>k;
        memset(dp,-1,sizeof dp);
        int ans = f1(n,k,0); 
        ans+=f1(n,k,1);
        cout<<num<<" "<<ans<<"\n";
    }
    



    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
    return 0;
}