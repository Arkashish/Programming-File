
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
void levelorder_levelwise(node* root)
{
    if(root==NULL) return;
    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);
    while (not qu.empty())
    {
        if(qu.front()== NULL)
        {
            cout<<"\n";
            qu.pop();
            if(qu.size()==NULL) break;
            qu.push(NULL);
            continue;
        }
        node* temp = qu.front();
        qu.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        qu.push(temp->left);
        if(temp->right)
        qu.push(temp->right);

        
    }
    return;     
}
int max_level = INT_MIN;
void rightview(node *root,int curr_level)
{
    if(root==NULL) return;
    if(max_level<curr_level)
    {
        cout<<root->data<<" ";
        max_level=curr_level;
    }
    rightview(root->right,curr_level+1);
    rightview(root->left,curr_level+1);
}
int main()
{
    clock_t begin = clock();
    file_io();
    node* root = build();
    levelorder_levelwise(root);
    cout<<"\n";
    rightview(root,0);
    cout<<endl;
   
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}