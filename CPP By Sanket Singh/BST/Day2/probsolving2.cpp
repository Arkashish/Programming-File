
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
node *lcaans = NULL;
bool lca(node* root,node* n1,node* n2)
{
    if(root==NULL)
    return false;
    int left = lca(root->left,n1,n2);
    int right = lca(root->right,n1,n2);

    int curr = (root->data == n1->data or root->data == n2->data);
    if(left+right+curr>=2)
    {
        lcaans = root;
    }
    return (left+right+curr)>0;
}
int main()
{
    clock_t begin = clock();
    file_io();
    node *root = build();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}