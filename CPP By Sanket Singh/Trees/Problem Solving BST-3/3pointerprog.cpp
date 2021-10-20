
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
    node* next;
    node(int d)
    {
        data = d;
        left=NULL;
        right=NULL;
        next=NULL;
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
node* leftmost;
node* previ;
void process(node* child)
{
    if(child==NULL)
    return;
    if(previ!=NULL)
    {
        previ->next = child;
    }
    else
    {
        leftmost=child;
    }
    previ=child;
    
}
node* populate(node* root)
{
    if(root==NULL)
    return NULL;
    leftmost=root;
    node* curr = leftmost;
    while (leftmost!=NULL)
    {
        previ=NULL;
        curr=leftmost;
        leftmost=NULL;
        while (curr!=NULL)
        {
            process(curr->left);
            process(curr->right);
        }
        
    }
    return root;
}
int main()
{
    node* root = build();
    
    //i/p- 1 2 -1 3 -1 -1 2 -1 3 -1 -1  o/p- 1
}