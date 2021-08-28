
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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


vector<vector<ll>> preprocess(string str)
{
    int n = str.size();
    vector<vector<ll>> prefix(26,vector<ll>(n,0));
    for (int i = 0; i < 26; i++)
    {
        char ch = 'a' + i;
        for (int j = 0; j < n; j++)
        {
            if(ch==str[j])
            {
                prefix[i][j] = 1;
            }
        }
        //calculating the prefix sum
        for(int j=1;j<n;j++)
        {
            prefix[i][j] += prefix[i][j-1] ;
        }
        
    }
    return prefix;
}


int main()
{
    clock_t begin = clock();
    file_io();
    string s;
    cin>>s;
    vector<vector<ll>> prefix = preprocess(s);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        ll ans = 0;
        l--,r--; //converting one bases to zero based
        for (int i = 0; i < 26; i++)
        {
            int y=0;
            if(l-1>=0)
            {
                y = prefix[i][l-1];
            }
            int sum = prefix[i][r] - y;
            ans+= (sum*(sum+1))/2;

        }
        cout<<ans<<"\n";
        

    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
    return 0;
}