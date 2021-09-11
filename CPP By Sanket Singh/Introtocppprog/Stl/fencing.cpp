
// problem link - https://www.codechef.com/problems/FENCE
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
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

int main()
{
    clock_t begin = clock();
    file_io();
    unordered_map<int,unordered_map<int,int>> field;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y;
        int ans = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(k--)
        {
            cin>>x>>y;
            for(int i=0;i<4;i++)
            {
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                ans+=field[new_x][new_y]?-1:1;
            }
            field[x][y]=1;
        }
        cout<<ans<<"\n";
        field.clear();
    }
  
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
    return 0;
}

