
//Generic graph

#include<bits/stdc++.h>
using namespace std;
// T represents any general type - int/float/string
template <typename T>
class Graph{
    public:
    unordered_map<T,unordered_map<T,int>> adj;
    Graph()
    {

    }
    void add_edge(T u, T v,int wt ,bool bidir = true)
    {
        adj[u][v] = wt;//added an edge from u to w with weight wt
        if(bidir)
        {
            adj[v][u] = wt; 
        }
    }
    void print()
    {
        for(auto row: adj)
        {
            cout<<row.first<< " = ";
            for(auto el: row.second)
            {
                cout<<el.first<<","<<el.second<<"-->";
            }
            cout<<endl;
        }

    }
};

int main(int argc,char const *argv[])
{
    Graph<int> g1;
    Graph<string> g2;

    // g1.add_edge(1,2);
    // g1.add_edge(3,2);
    // g1.add_edge(4,2);
    // g1.add_edge(1,4);
    // g1.add_edge(1,3);
    // g1.print();

    // cout<<"\n\n";
    g2.add_edge("del","mum",350);
    g2.add_edge("del","blr",630);
    g2.add_edge("kol","mum",720);
    g2.add_edge("mum","goa",125);
    g2.add_edge("goa","kol",350);
    g2.add_edge("kol","del",540);
    g2.print();

}