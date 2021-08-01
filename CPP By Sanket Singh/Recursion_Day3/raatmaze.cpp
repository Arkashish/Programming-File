
#include<bits/stdc++.h>
using namespace std;
int totalpaths = 0;
void ratmaze(int i,int j,int m,int n,string osf)
{
    //base case1 - incase i or j crosses the wall
    if(i>=m or j>=n)
    return;

    if(i==m-1 and j== n-1)
    {
        totalpaths++;
        cout<<osf<<endl;
        return;
    }

    //recursive intution and self work
    ratmaze(i,j+1,m,n,osf + "R");//right move
    ratmaze(i+1,j,m,n,osf + "D");//down move
    //ratmaze(i+1,j+1,m,n,osf + "->");//diagonal move

}
int main()
{
    ratmaze(0,0,3,3,"");
    cout<<"\nTotal number of paths are: "<< totalpaths<<endl;
}