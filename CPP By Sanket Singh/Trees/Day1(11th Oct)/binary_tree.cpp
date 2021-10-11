
#include<bits/stdc++.h>
using namespace std;

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
void preorder(node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node* root = build();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}