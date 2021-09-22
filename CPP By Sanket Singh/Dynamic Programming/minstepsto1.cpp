
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
ll minstepsto1TD(int n,ll *dp)
{
    if(n==2 or n==3) return 1;
    if(n==1) return 0;
    if(n<1) return inf;
    if(dp[n]!=0) return dp[n];
    ll divby3=inf,divby2=inf,subby1=inf;
    if(n%3==0)
    divby3=1+minstepsto1TD(n/3,dp);
    if(n%2==0)
    divby2 =1+minstepsto1TD(n/2,dp);
    
    subby1=1+minstepsto1TD(n-1,dp);
    return dp[n]=min({divby3,divby2,subby1});
}
ll minstepsto1BU(int n)
{
    ll *dp = new ll[n+1]();
    dp[0] = inf;
    dp[1] = 0;
    dp[2]=dp[3]=1;
    for(int i=4;i<=n;i++){
        ll divby3=inf,divby2=inf,subby1=inf;
        if(n%3==0)
            divby3=1+dp[i/3];
        if(n%2==0)
            divby2 =1+dp[i/2];
        subby1=1+dp[i-1];
        dp[i] = min({divby2,divby3,subby1});

    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    ll *dp = new ll[n+1]();
    cout<<minstepsto1TD(n,dp)<<"\n";
    cout<<minstepsto1BU(n)<<"\n";


}