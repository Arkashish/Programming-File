
//Date - 9/02/2021
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};
int sum=0;
Node* convert(Node* root)
{
    if(root==NULL) 
        return root;

    convert(root->right);
    root->data = root->data + sum;
    sum = root->data;
    convert(root->left);

    return root;
}
int main()
{

}