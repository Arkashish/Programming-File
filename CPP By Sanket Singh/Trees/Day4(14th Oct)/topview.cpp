
//Solution by: Arka

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
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
struct node
{
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}
// int c=0;
map<int,int> mp;
void preorder(node *root,int c)
{
    if(root==NULL)
    return;
    mp.insert({c,root->data});
    preorder(root->left,c-1);
    preorder(root->right,c+1);
}
int main()
{
    clock_t begin = clock();
    file_io();
    node *root = build();
    preorder(root,0);
    for(auto it : mp)
    {
        cout<<it.second<<" ";//it.first<<
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}
//i/o - 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
//o/p - 4 2 1 3 6 