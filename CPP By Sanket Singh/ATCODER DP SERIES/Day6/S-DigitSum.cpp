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
ll dp[100005][105][2];
ll digitsum(string &k, int D, int pos, int d, bool c)
{
    if (dp[pos][d][c] != -1)
        return dp[pos][d][c];
    int ub = (c) ? (k[pos] - '0') : 9;
    if (pos == k.size() - 1)
    {
        ll ans = 0;
        for (int i = 0; i <= ub; i++)
        {
            if (i % D == d)
                ans++;
        }
        return ans;
    }
    ll ans = 0;
    for (int i = 0; i <= ub; i++)
    {
        ans = (ans % mod + digitsum(k, D, pos + 1, (D + d - i % D) % D, c && (i == ub)) % mod) % mod;
    }
    return dp[pos][d][c] = ans;
}
int main()
{
    clock_t begin = clock();
    file_io();
    int D;
    string k;
    cin >> k;
    cin >> D;
    memset(dp, -1, sizeof(dp));
    cout << (mod+ digitsum(k, D, 0, 0, 1) - 1)%mod << "\n"; // -1 for 1 extra value

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}