
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    public:
    unordered_map<T,list<pair<T,int>>> adj;
    Graph()
    {

    }
    void add_edge(T n1, T n2,int wt, bool bidir = true)
    {
        adj[n1].push_back(make_pair(n2,wt));
        if(bidir)
        {
            adj[n2].push_back(make_pair(n1,wt));
        }
    }
    void print()
    {
        for(auto row: this->adj)
        {
            cout<<row.first<< "-->";
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

    cout<<"\n\n";
    g2.add_edge("del","mum",350);
    g2.add_edge("del","blr",630);
    g2.add_edge("kol","mum",720);
    g2.add_edge("mum","goa",125);
    g2.add_edge("goa","kol",350);
    g2.add_edge("kol","del",540);
    g2.print();
}