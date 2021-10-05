#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll,ll>
#define vi vector<ll>
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
vector<vector<pii>> adj;

vi bfs(int src,int c,int n)
{
    queue<int> qu;
    vi dist(n+1,-1);
    qu.push(src);
    dist[src] = 0;
    while (!qu.empty())
    {
        int i = qu.front();
        qu.pop();
        for(pii nb : adj[i])
        {
            if (dist[nb.first]!=-1 or nb.second!=c)
            {
                continue;
            }
            qu.push(nb.first);
            dist[nb.first] = dist[i]+1;

            
        }
    }
    return dist;
    
}
int main()
{
    clock_t begin = clock();
    file_io();
    int n,m;
    cin>>n>>m;
    adj.reserve(n+1);
    while (m--)
    {
        int i,j,c;
        cin>>i>>j>>c;
        adj[i].push_back(make_pair(j,c));
        adj[j].push_back(make_pair(i,c));
    }
    int src,dest;
    cin>>src>>dest;
    vi ds = bfs(src,0,n);
    vi dd = bfs(dest,1,n);
    ll ans = inf;
    for(int i=1;i<=n;i++)
    {
        if(i==src or i==dest or ds[i]==-1 or dd[i]==-1 or dd[dest]==-1)
        {
            continue;
        }
        ans = min(ans,ds[i]+dd[i]);
    }
    if(ans==inf)
    ans=-1;
    cout<<ans<<endl;
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}