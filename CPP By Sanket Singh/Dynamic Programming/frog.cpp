
#include <bits/stdc++.h>
using namespace std;
// int min(int a ,int b)
// {
//     if(a>b)
//     return b;
//     else 
//     return a;
// }
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = abs(ar[2] - ar[1]);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min((dp[i - 1] + abs(ar[i] - ar[i - 1])), (dp[i - 2] + abs(ar[i - 2] - ar[i])));
    }
    cout<<dp[n]<<endl;
}