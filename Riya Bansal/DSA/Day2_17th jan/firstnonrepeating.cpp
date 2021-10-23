#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define loop(i,a,b) for(int i = (a); i <= (b); i++)
#define revloop(i,a,b) for(int i = (b); i >= (a); i--)
#define pb push_back
#define ump unordered_map
int main()
{
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(int i=0;s[i]!='\0';i++)
    {
        char ch = s[i];
        if(mp.find(ch) == mp.end())
        {
            mp.insert(make_pair(ch,1));
        }
        else
        {
            mp[ch]++;
        }
    }
    int notf=1;
    for(int i=0;s[i]!='\0';i++)
    {
        char ch = s[i];
        if(mp[ch]==1)
        {
            cout<<ch<<endl;
            notf=0;
            break;
        }
    }
    if (notf==1)
    {
        cout<<-1<<endl;
    }
    
}