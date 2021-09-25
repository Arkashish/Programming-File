
//Problem link - https://code.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
//check this some error is occuring
#include <bits/stdc++.h>
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
//top down
ll dp[2005][2005][8];
ll klcs(vector<ll> &a1, vector<ll> &a2, int i, int j, int k)
{
    if (i == a1.size() and j == a2.size())
        return 0;
    if (dp[i][j][k] != -1){
        return dp[i][j][k];}
    ll ans;
    if (a1[i] == a2[j]){
        ans = 1 + klcs(a1, a2, i + 1, j + 1, k);
        return dp[i][j][k] = ans;
        }
    else
    {
        ll c1 = klcs(a1, a2, i + 1, j, k);
        ll c2 = klcs(a1, a2, i, j + 1, k);
        ll c3=-1;

        if (k > 0){
            c3 = 1 + klcs(a1, a2, i + 1, j + 1, k - 1);
        }
            ans = max({c1,c2,c3});
            return dp[i][j][k] =ans;

    }
}

int main()
{
    clock_t begin = clock();
    file_io();
    int n, m, k;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    vector<ll> a1(n);
    vector<ll> a2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }
    cout << klcs(a1, a2, 0, 0, k) << endl;
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}