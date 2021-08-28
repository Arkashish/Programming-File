
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    // int val = *max_element(v.begin(),v.end());
    // cout<<val<<"\n";

    // if(binary_search(v.begin(),v.end(),3))
    // cout<<"present";
    // else
    // {
    //     cout<<"absent";
    // }
    
    //sorting in  reverse order

    sort(v.begin(),v.end(),greater<int> ());
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}