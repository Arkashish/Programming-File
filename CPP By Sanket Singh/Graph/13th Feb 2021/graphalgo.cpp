// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
 
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
 
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
 
 
class Graph {
public:
	int v; // no of vertices
	list<int> *adj; // array of linked list -> adjacency list
	// constrcutror
	Graph(int v) {
		this->v = v;
		adj = new list<int>[v];
	}
 
	// adds an edge between vertex u and v
	void addEdge(int u, int v, bool bidir = true) { 
		// if bidir == true -> graph is undirected
		// insert at last to the list storing neighbours of u
		adj[u].push_back(v); 
		if(bidir) {
			adj[v].push_back(u);
		}
	}
 
	void dfsHelper(int src, unordered_set<int> &visited) {
		// mark the current node as visited
		visited.insert(src);
		cout<<src<<" ";
		for(int neighbour : adj[src]) {
			if(visited.count(neighbour) == 0) {
				dfsHelper(neighbour, visited);
			}
		}
	}
 
	void DFS() {
		unordered_set<int> visited;
		for(int i = 0; i < this->v; i++) {
			if(visited.count(i) == 0) {
				dfsHelper(i, visited);
			}
		}
	}
 
 
	void bfsHelper(int src, bool *visited) {
		queue<int> qu;
		qu.push(src);
		visited[src] = true;
		while(not qu.empty()) {
			int curr = qu.front();
			cout<<curr<<" ";
			qu.pop();
			for(int neighbour: adj[curr]) {
				if(not visited[neighbour]) {
					qu.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
	void BFS() {
		bool *visited = new bool[this->v]();
		for(int i = 0; i < this->v; i++) {
			if(visited[i] == false) {
				bfsHelper(i, visited);
			}
		}
		delete [] visited;
	}
 
	int noOfCC() {
		int count = 0;
		unordered_set<int> visited;
		for(int i = 0; i < this->v; i++) {
			if(visited.count(i) == 0) {
				count++;
				dfsHelper(i, visited);
			}
		}
		return count;
	}
};
 
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	Graph g(n);
	int e; // no of edges
	cin>>e;
	while(e--) {
		int u, v;
		cin>>u>>v;
		g.addEdge(u, v);
	}
	g.DFS();
	cout<<endl;
	g.BFS();
 
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
 