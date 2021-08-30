
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[105][105][2];

ll f(int n, int k, int s)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        if (k == 0)
            return 1;
        else
            return 0;
    }
    ll res = -1;
    if (dp[n][k][s] != -1)
        return dp[n][k][s];
    if (s == 0)
    {
        res = f(n - 1, k, 0) + f(n - 1, k, 1);
    }
    else
    {
        res = f(n - 1, k, 0) + f(n - 1, k - 1, 1);
    }
    return dp[n][k][s] = res;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int num, n, k;
    cin >> num >> n >> k;
    memset(dp, -1, sizeof dp);
    int ans = f(n, k, 0);
    ans += f(n, k, 1);
    cout << num << " " << ans << "\n";
    }
}