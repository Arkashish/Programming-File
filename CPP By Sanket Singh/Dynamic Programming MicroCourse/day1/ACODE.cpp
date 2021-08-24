
//Problem link - https://www.spoj.com/problems/ACODE/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[100005];
//top down approach
ll f(string &s, int i)
{
    if (i == 0 or i == 1)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    ll ans = 0;
    if (s[i - 1] - '0' > 0)
        ans += f(s, i - 1);
    if (i - 2 >= 0 and s[i - 2] - '0' > 0 and (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
        ans += f(s, i - 2);

    return dp[i] = ans;
}

//bottom up approach

ll g(string &s)
{
    vector<ll> dp(s.size(),0);
    dp[0] = dp[1] = 1;
    if (((s[0]-'0') * 10 + (s[1]-'0')) <= 26)
        dp[1] += 1;
    for (int i = 2; i < s.size(); i++)
    {
        dp[i] = dp[i - 1] + (((10 *( s[i - 1]-'0') + (s[i]-'0')) <= 26) ? dp[i - 2] : 0);
    }
    return dp[s.size() - 1];
}

int main()
{
    string s;
    cin >> s;

    //top down approach
    while (s[0]!='0')
    {
        std:memset(dp,-1,sizeof dp);
        cout<<f(s,s.size())<<"\n"; //since we are considering from the last element
        cin>>s;
    }

    //bottom up approach
    while (s[0] != '0')
    {
        cout << g(s) << "\n";
        cin >> s;
    }
}