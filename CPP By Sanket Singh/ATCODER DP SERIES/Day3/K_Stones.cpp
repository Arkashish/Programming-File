
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
string stones(vector<int> &ar,ll k)
{
    vector<bool> dp(k+1,false);
    for(int i=1;i<=k;i++)
    {
        for(int val: ar)
        {
            if(val>i) continue;
            if(dp[i-val] == false)
            dp[i] = true;
        }
    }
    return dp[k] ? "First" : "Second";
}
int main()
{
    clock_t begin = clock();
    file_io();

    ll n,k;
    cin>>n>>k;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];

    cout<<stones(ar,k)<<"\n";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}