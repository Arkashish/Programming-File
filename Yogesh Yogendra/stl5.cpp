
#include <bits/stdc++.h>
using namespace std;

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
//finding max element in an array in O(N)
void maxelement(vector<int> &v)
{
    int val = *max_element(v.begin(),v.end());
    cout<<val<<"\n";
}
//sorting in  reverse order
void sort(vector<int> &v)
{
    sort(v.begin(),v.end(),greater<int> ());
}
//printing vector
void print(vector<int> &v)
{
     for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
void binsearchstl(vector<int> &v)
{
    
    if(binary_search(v.begin(),v.end(),3))
    cout<<"present";
    else
    {
        cout<<"absent";
    }
    
}
bool compare(pair<int,int> a,pair<int,int> b)
{   
    if(a.first == b.first)
    {
        return a.second>b.second;
    }
    return a.first>b.first;
}
void pairvectors(int n,int k)
{
    int x,y;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        ans.push_back({x,y});
    }
    cout<<"Original Vector: \n";
    for (int i = 0; i < n; i++)
    {
        cout<< ans[i].first << " " << ans[i].second <<"\n";
    }
    cout<<"\nSorted Vector: \n";
    //now sorting the vector
    if(k==1)
        sort(ans.begin(),ans.end());
    else
    {
        sort(ans.begin(),ans.end(),compare);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<< ans[i].first << " " << ans[i].second <<"\n";
    }

}

int main(int argc, char* argv[])
{
    clock_t begin = clock();
    file_io();
    int n;
    cin>>n;
    int k;
    cin>>k;//for ascending press 1 while for descending press 2
    // vector<int> v(n,0);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>v[i];
    // }
    //pairvectors(n,k);
    cout<<"\n";
    //count number of set bits
    cout<<__builtin_popcount(n);
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
    return 0;
}