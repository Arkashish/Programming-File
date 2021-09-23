#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
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
ll dp[405][405];
ll sum[405][405];

ll slimes(vector<int> &a, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll mincost = inf;
    for (int k = i; k < j; k++)
    {
        mincost = min({mincost, slimes(a, i, k) + slimes(a, k + 1, j) + sum[i][j]});
    }
    return dp[i][j] = mincost;
}
//This program uses concept of matrix chaining multiplication
int main()
{
    clock_t begin = clock();
    file_io();
    memset(dp, -1, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    ll n, k;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sum[i][j] = a[j] + ((i == j) ? 0 : sum[i][j - 1]);
        }
    }
    cout << slimes(a, 1, n) << "\n";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}