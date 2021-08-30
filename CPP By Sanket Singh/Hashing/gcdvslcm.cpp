
#include<iostream>
#include<unordered_map>
using namespace std;


int main()
{
    int t;
    cin>>t;
    unordered_map<int,int> mp;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mp[x]++;
        }
        long long int ans = 0;
        for(auto it: mp)
        {
            if(mp.count(2*it.first)){
                ans+=mp[it.first]*mp[2*(it.first)];
            }
        }
        cout<<ans<<"\n";
        mp.clear();
    }
}