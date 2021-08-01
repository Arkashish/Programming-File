
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    public:
    unordered_map<T,list<T>> adj;
    Graph()
    {

    }
    void add_edge(T n1, T n2, bool bidir = true)
    {
        adj[n1].push_back(n2);
        if(bidir)
        {
            adj[n2].push_back(n1);
        }
    }
    void print()
    {
        for(auto row: this->adj)
        {
            cout<<row.first<< "-->";
            for(T el: row.second)
            {
                cout<<el<<",";
            }
            cout<<endl;
        }

    }
};

int main(int argc,char const *argv[])
{
    Graph<int> g1;
    Graph<string> g2;

    g1.add_edge(1,2,false);
    g1.add_edge(3,2,false);
    g1.add_edge(4,2,false);
    g1.add_edge(1,4,false);
    g1.add_edge(1,3,false);
    g1.print();

    cout<<"\n\n";
    g2.add_edge("dl","tn",false);
    g2.add_edge("dl","blr",false);
    g2.add_edge("dl","mb",false);
    g2.add_edge("mb","blr",false);
    g2.add_edge("kol","blr",false);
    g2.add_edge("kol","dl",false);
    g2.print();

}