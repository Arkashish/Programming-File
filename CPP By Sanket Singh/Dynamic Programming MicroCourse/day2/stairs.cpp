
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 10000007;

ll f(int n)
{
    vector<ll> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (j > i)
                continue;

            dp[i] = ( (dp[i] % 1000007) + (dp[i - j] % 1000007)) % mod;
        }
    }
    return dp[n];
}
int main()
{
    ll n;
    cin >> n;
    cout << f(n) << "\n";
}