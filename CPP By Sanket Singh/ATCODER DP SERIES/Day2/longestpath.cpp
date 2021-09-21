
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

vector<int> graph[100005];
int dp[100005];
int findlongestpath(int src)
{
    if (dp[src] != -1)
        return dp[src];
    int res = INT_MIN;
    bool noneighbour = true;
    for (int neighbour : graph[src])
    {
        noneighbour = false;
        res = max(res, findlongestpath(neighbour));
    }
    return noneighbour ? 0 : res + 1;
}
int main()
{
    clock_t begin = clock();
    file_io();

    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int res = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, findlongestpath(i));
    }
    
    cout << res << "\n";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
}