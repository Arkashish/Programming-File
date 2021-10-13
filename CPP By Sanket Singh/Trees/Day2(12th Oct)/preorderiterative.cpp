
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

void preorder_iteraative(node *root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*> st;
    st.push(root); //this is the first node to be processed
    while (not st.empty())
    {
        cout<<st.top()->data<<" ";
        node* curr = st.top();
        st.pop();
        if(curr->right)
        {
            st.push(curr->right);
        }
        if(curr->left)
            st.push(curr->left);
    }
    return;    
}
int main()
{
    clock_t begin = clock();
    file_io();
    node* root = build();
    preorder_iteraative(root);
    cout<<"\n";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}
//I?O - 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 9 -1 -1 7 -1 -1