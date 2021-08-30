
#include<bits/stdc++.h>
using namespace std;

bool anagram(string &s1,string &s2)
{
    if(s1.size()!=s2.size())
        return false;
    unordered_map<char,int> mp;
    for(int i=0;i<s1.size();i++)
    {
        mp[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++)
    {
        if(mp.count(s2[i])==0)
            return false;
        mp[s2[i]]--;
        if(mp[s2[i]]<=0)
        mp.erase(s2[i]);
    }
    return true;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(anagram(s1,s2))
    cout<<"Yes"<<"\n";
    else
    cout<<"No"<<"\n";
}