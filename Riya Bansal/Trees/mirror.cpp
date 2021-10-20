
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define MAX(x,y) (x>y)?x:y
#define MIN(x,y) (x<y)?x:y
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
struct node{
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left=NULL;
        right=NULL;
    }
};

node* build()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    node *root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}
bool ismirror(node* t1,node* t2)
{
    if(t1==NULL and t2==NULL) return true;
    if(t1==NULL or t2==NULL) return false;

    return ((t1->data==t2->data) and ismirror(t1->left,t2->right) and ismirror(t1->right,t2->left));
}
bool issymmetric(node* root)
{
    return ismirror(root,root);
}
int main()
{
    clock_t begin = clock();
    file_io();
    node* root = build();
    cout<<issymmetric(root)<<endl;
  
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}