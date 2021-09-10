
//Asked in Google
#include<bits/stdc++.h>
using namespace std;

bool xorpair(vector<int> &a1,vector<int> &a2)
{
    int n = a1.size();
    int v=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        v = v^a1[i];
        v = v^a2[i];
        mp[a2[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        int x = a1[i]^v;
        if(mp.count(x)>0)
        {
            mp[x]--;
            if(mp[x]==0) mp.erase(x);
        }else{
            return false;
        }
    }
    return true;
}
int main()
{
    
}