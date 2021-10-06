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
vector<vector<ll>> graph;
void addedge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfshelper(int src,vector<bool> &visited)
{
    visited[src] = true;
    cout<<src<<" ";
    for(auto neighbour : graph[src])
    {
        if(not visited[neighbour])
        {
            dfshelper(neighbour,visited);
        }

    }
}
void dfs(int src,int v)
{
    vector<bool> visited(v,false);
    dfshelper(src,visited);
}
int main()
{
    clock_t begin = clock();
    file_io();
    int v,e;
    cin>>v>>e;
    graph.resize(v+1);
    while(e--)
    {
        int u,n;
        cin>>u>>n;
        addedge(u,n);
    }
    dfs(1,v+1);
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}