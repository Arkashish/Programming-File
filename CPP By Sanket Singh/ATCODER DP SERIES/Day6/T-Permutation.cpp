//Check this one

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
ll dp[3005][3005];
void permutation(string &s, int n)
{
    dp[n][0] = (s[n - 2] == '>') ? 1 : 0;
    dp[n][1] = (s[n - 2] == '<') ? 1 : 0;
    for (int i = n - 1; i >= 2; i--)
    {
        int total = n - i + 1;
        for (int g = 0; g <= total; g--)
        {
            if (g == 0)
            {
                dp[i][g] = 0;
                if (s[i - 2] == '<')
                    continue;

                for (int j = 1; j <= total; j++)
                {
                    dp[i][g] = (dp[i][g]%mod + dp[i + 1][total - j]%mod) % mod;
                }
            }
            else
            {
                if (s[i - 2] == '>')
                {
                    dp[i][g] = (mod + dp[i][g - 1]%mod - dp[i + 1][g - 1]%mod) % mod;
                }
                else
                {
                    dp[i][g] = (dp[i][g - 1]%mod + dp[i + 1][g - 1]%mod) % mod;
                }
            }
        }
    }
}
int main()
{
    clock_t begin = clock();
    file_io();

    int n;
    string s;
    cin >> n;
    cin >> s;

    permutation(s, n);
    ll ans = 0;
    for (int g = n - 1; g >= 0; g--)
    {
        ans = (ans % mod + dp[2][g] % mod) % mod;
    }
    cout << ans << "\n";
    cout<<"WW"<<"\n";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}