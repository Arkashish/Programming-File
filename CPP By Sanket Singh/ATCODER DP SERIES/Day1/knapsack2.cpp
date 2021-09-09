
//problem link - https://atcoder.jp/contests/dp/tasks/dp_e
//check this prog..not passing all test cases

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9

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

int main(int argc, char *argv[])
{
    clock_t begin = clock();
    file_io();

    ll n, w;
    cin >> n >> w;
    vector<ll> wt(n);
    vector<ll> val(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    ll dp1[n * 1000 + 1];
    ll dp2[n * 1000 + 1];
    for (ll i = 0; i <= n * 1000; i++)
    {
        dp1[i] = inf;
        dp2[i] = inf;
    }
    dp1[0] = 0;
    dp1[val[0]] = wt[0]; //base case

    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j <= n * 1000; j++)
        {
            if (val[i] > j)
                dp2[j] = dp1[j]; //we cannot pick
            else
            {
                //we can or cannot pick as per our choice
                dp2[j] = min({dp1[j],wt[i] + dp1[j-val[i]]});
            }
        }
        for(ll k=0;k<=n*1000;k++)
        {
            dp1[k] = dp2[k];
            dp2[k] = inf;
        }
    }

    ll result = 0;
    for(ll i=0;i<=n*1000;i++)
    {
        if(dp1[i]<=w) result=i;
    }
    cout<<result<<"\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
    return 0;
}