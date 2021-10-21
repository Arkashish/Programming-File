

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define loop(i,a,b) for(int i = (a); i <= (b); i++)
#define revloop(i,a,b) for(int i = (b); i >= (a); i--)

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
class Node
{
public:
    char data;
    bool terminal;
    unordered_map<char, Node *> children;
    Node(char ch)
    {
        this->data = ch;
        this->terminal = false;
    }
};
class Trie
{
public:
    Node *root;
    Trie(){
        this->root = new Node('\0');
    }
    void insert(string str)
    {
        Node* temp = this->root;
        loop(i,0,str.size()-1)
        {
            char ch = str[i];
            if(temp->children.count(ch))
            {
                //yes
                temp = temp->children[ch];
            }
            else
            {
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp=temp->children[ch];
            }
            
        }
        temp->terminal=true;
    }
    void dfs(Node* temp,string str,string output)
    {
        if(temp==NULL) return;
        if(temp->terminal) cout<<str+output<<endl;
        for(auto child : temp->children)
        {
            dfs(child.second,str,output+child.first);
        }
    }
    void autocomplete(string str)
    {
        Node* temp = this->root;
        loop(i,0,str.size()-1)
        {
            char ch = str[i];
            if(temp->children.count(ch))
            {
                temp = temp->children[ch]; 
            }
            else
            {
                return;
            }
            
        }
        dfs(temp,str,"");
    }
};


int main()
{
    clock_t begin = clock();
    file_io();
    Trie t;
    int n;
    cin>>n;
    while (n--)
    {
        string str;
        cin>>str;
        t.insert(str);
    }
    t.autocomplete("sa");
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}
