
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
ll dp[3005][3005];
ll arr[3005];
ll dequeue(int i,int j)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i==j)
    return dp[i][j] = arr[i];
    return dp[i][j] = max(arr[i]-dequeue(i+1,j),arr[j]-dequeue(i,j-1));

}
int main()
{
    clock_t begin = clock();
    file_io();
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<dequeue(0,n-1)<<"\n";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}