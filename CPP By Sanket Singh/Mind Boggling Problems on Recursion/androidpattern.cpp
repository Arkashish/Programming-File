

#include<bits/stdc++.h>
using namespace std;

void file_io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int skip[10][10];
int helper(vector<bool> &visited,int currdigit,int remaindigit)
{
    if(remaindigit<0) return 0;
    if(remaindigit == 0)
    return 1;

    visited[currdigit] = true;
    int result = 0;
    for (int i = 1; i < 10; i++)
    {
        if(not visited[i] and (skip[currdigit][i] ==0 or visited[skip[currdigit][i]]==true))
            result +=helper(visited,i,remaindigit-1);
    }
    visited[currdigit] = false;
    return result;
}
int countpatterns(int m,int n)
{
    for (int i = 0; i < 10; i++)
    {
        for(int j=0;j<10;j++)
        {
            skip[i][j] = 0;
        }
    }
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;

    vector<bool> visited(10,false);
    int result = 0;
    for(int i=m;i<=n;i++)
    {
        result+=helper(visited,1,i-1)*4;//we are using i-1 because we have already started from 1
        result+=helper(visited,2,i-1)*4;//we are using i-1 because we have already started from 2
        result+=helper(visited,5,i-1);
    }

    return result;
}
int main()
{
    clock_t begin = clock();
    file_io();
    int n,m;
    cin>>m>>n;
    
    cout<<countpatterns(m,n)<<"\n";

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\n"<<"Executed in: "<<double(end-begin)/CLOCKS_PER_SEC<<"ms \n";
    #endif
    return 0;
}