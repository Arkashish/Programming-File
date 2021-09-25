#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define endl "\n"
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
struct flower{
    ll h,b;
};

ll flowers(vector<flower> &a,int n)
{
    vector<ll> dp(n+1);
    map<ll,ll> sortedflowers;
    dp[1] = a[1].b;
    sortedflowers[a[1].h] = a[1].b;
    ll ans = dp[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = a[i].b;
        auto it = sortedflowers.lower_bound(a[i].h+1);
        if (it!=sortedflowers.begin())
        {
            it--;
            dp[i] += it->second;
        }
        sortedflowers[a[i].h]=dp[i];
        it = sortedflowers.upper_bound(a[i].h);
        while (it!=sortedflowers.end() and it->second <= dp[i]) 
        {
            auto t = it;
            t++;
            sortedflowers.erase(it);
            it = t;
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}
int main()
{
    clock_t begin = clock();
    file_io();

    int n;
    cin>>n;
    vector<flower> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].h;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].b;
    }
    cout<<flowers(arr,n);
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}

//Test Case
// 4
// 3 1 4 2
// 10 20 30 40
