
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
bool isidentical(node* t1,node* t2)
{
    if(t1==NULL and t2==NULL) return true;
    if(t1==NULL or t2==NULL) return false;

    return ((t1->data==t2->data) and isidentical(t1->left,t2->left) and isidentical(t1->right,t2->right));
}
bool issymmetric(node* root)
{
    return isidentical(root->left,root->right);
}
int main()
{
    node* root = build();
    cout<<issymmetric(root)<<endl;
    //i/p- 1 2 -1 3 -1 -1 2 -1 3 -1 -1  o/p- 1
}