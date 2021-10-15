
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
int height(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
        return 0;

    int left_ = diameter(root->left);
    int right_ = diameter(root->right);

    int lh = height(root->left);
    int rh = height(root->right);
    int via_root = lh + rh + (root->left != NULL) + (root->right != NULL);
    return max({lh, rh, via_root});
}
//The above algo takes O(n^2) time since it is iterating over the diameter once and then in the height as well
// Now we can optimize it using dp
pair<int, int> diameter_betr(node *root)
{
    if((root == NULL) or (root->left == NULL and root->right == NULL))
    {
        pair<int, int> p;
        p.first = 0;  //height
        p.second = 0; //diameter
        return p;
    }

    pair<int,int> left_ = diameter_betr(root->left);
    pair<int,int> right_ = diameter_betr(root->right);

    int h = max(left_.second,right_.second)+1; //height
    int d = max({left_.first,right_.first,left_.second+right_.second+2 });
    return {d,h};
}
int main()
{
    clock_t begin = clock();
    file_io();
    node *root = build();
    cout << diameter(root);
    cout << endl;

    pair<int,int> p = diameter_betr(root);
    cout<<p.first<<endl; 
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}
//i/o - 1 2 -1 4 -1 7 -1 -1 3 5 -1 8 -1 10 -1 12 -1 -1 6 -1 9 -1 11 -1 13 -1 14 -1 -1
//o/p - 9
//      9
