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
vector<vector<pair<int,int>>> graph;
void addEdge(int u,int v,bool bidir=true,int wt=0)
{
    graph[u].push_back(make_pair(v,wt));
    if(bidir)
    {
        graph[v].push_back(make_pair(u,wt));
    }
}
void display()
{
    for(auto i : graph)
    {
        //i->vector of pair
        if(i.size()==0)
        cout<<"Empty";
        for(auto j : i)
        {
            //j is a pair
            cout<<"{"<<j.first<<","<<j.second<<"} ";
        }
        cout<<endl;
    }
}
void bfs(int src,int vertices)
{
    queue<int> qu;
    vector<bool> visited(vertices,false);
    qu.push(src);
    visited[src] = true;
    while (!qu.empty())
    {
        int currnode = qu.front();
        qu.pop();
        cout<<currnode<<" ";
        for (auto neighbour : graph[currnode])
        {
            //neighbour is a pair
            if(not visited[neighbour.first])
            {
                qu.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
        
    }
    
}
int main()
{
    clock_t begin = clock();
    file_io();
    int vertices,edges;
    cin>>vertices>>edges;
    graph.resize(vertices);
    while (edges--)
    {
        // int u,v,bidir,wt;
        int u,v,wt;
        // cin>>u>>v>>bidir>>wt;
        cin>>u>>v>>wt;
        //undirected graph
        addEdge(u,v,true,wt);
        //for directed grapph
        // addEdge(u,v,false,wt);
    }
    display();
    bfs(1,vertices);
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}