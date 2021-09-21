
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
double dp[302][302][302];
double sushi(ll x,ll y,ll z,int n)
{
    if(x<0 or y<0 or z<0) return 0;
    if(x==0 and y==0 and z==0)
    return 0;
    if(dp[x][y][z]>-0.9)
    return dp[x][y][z];
    double exp = n+x*sushi(x-1,y,z,n)+y*sushi(x+1,y-1,z,n)+z*sushi(x,y+1,z-1,n);
    return dp[x][y][z]=exp/(x+y+z);
}
int main()
{
    clock_t begin = clock();
    file_io();

    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    ll one=0,two=0,three=0;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(x==1) one++;
        else if (x==2) two++;
        else three++;
    }
    cout<<fixed<<setprecision(10)<<sushi(one,two,three,n)<<"\n";
  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
}