
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left,*right;
};

vector<int> levelorder(node *root)
{
    vector<int> v;
    if(root == NULL)
    return v;

    queue<node*> q;
    q.push(root);

    while(q.empty()!=false)
    {
        node* ptr = root;
        q.pop();

        v.push_back(ptr->data);

        if(ptr->left!=NULL)
            q.push(ptr->left);

        
        if(ptr->right!=NULL)
            q.push(ptr->right);
    }

}
int main()
{

}