
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
#define dec2bin(n) std::bitset<8>(n).to_string()
#define str2int(n) std::stoi(n)
#define bin2dec(n) std::stoi(bin, nullptr, 2)
int reversDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
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
vector<int> compute(string pat)
{
    vector<int> v(pat.length());
    v[0]=0;
    int j=0;
    loop(i,1,pat.length()-1)
    {
        if(pat[i]==pat[j])
        {
            v[i]=j+1;
            i++,j++;
        }
        else
        {
            if (j!=0)
            {
                j = v[j-1];
            }
            else
            {
                v[i]=0;
                i++;
            }
            
        }
        
    }
    return v;
}
int kmalgo(string text,string pat)
{
    vector<int> lps(pat.length());
    lps = compute(pat);
    int i=0,j=0;
    while (i<text.length() and j<pat.length())
    {
        if(text[i]==pat[j])
        {
            i++,j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                //j==0
                lps[j]=0;
                i++;
            }
        }
    }
    if(j==pat.length())
    return true;
    
    return false; 
    
}
int main()
{
    // clock_t begin = clock();
    //file_io();
    string text = "abcxabcdabcdabcy";
    string pt = "abcda";
    if(kmalgo(text,pt))
    cout<<"True"<<endl;
    else
    {
        cout<<"False";
    }
    
// #ifndef ONLINE_JUDGE
//     clock_t end = clock();
//     cout << "\n\n"
//          << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
// #endif
}