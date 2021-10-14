
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define MAX(x,y) (x>y)?x:y
#define MIN(x,y) (x<y)?x:y
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
double f(double t,int n,vi &s, vi &d)
{
    double mx = 0.0, mn = 1e18,val;
    for(ll i=0;i<n;i++)
    {
        val = s[i]*t + d[i];
        mx=max(val,mx);
        mn=max(val,mn);
    }
    return mx-mn;
}
int ternary(vector<ll> &arr,int target)
{
    int l=0,r=arr.size()-1;
    while (l<=r)
    {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if(arr[m1]==target) return m1;
        if(arr[m2]==target) return m2;
        if (target<arr[m1])
        {
            r=m1-1;
        }
        else if(target>arr[m2])
        {
            l=m2+1;
        }
        else if(arr[m1]<target and arr[m2]>target)
        {
            l=m1+1;
            r=m2-1;
        }
    }
    return -1;
}
int main()
{
    clock_t begin = clock();
    file_io();
    int n,k;
    cin>>n>>k;
    vi s,d;
    double l = 0.0,r=(double)k,m1,m2,e=1e-7,ans;
    while ((r-l)>e)
    {
        m1 = l+(r-l)/3;
        m2 = r-(r-l)/3;
        if(f(m1,n,s,d)>f(m2,n,s,d ))
        {
            l=m1;
        }
        else
        {
            r=m2;
        }
        
    }
    // ans=f(l);

    
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}