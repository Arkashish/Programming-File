
#include<bits/stdc++.h>
using namespace std;
int totpath=0;
void dicepath(int n,int i,string osf)
{
    if(i>=n)
    return;

    if(i==n-1)
    {
        totpath++;
        cout<<osf<<endl;
        return;
    }
    for(int j=1;j<=n;j++)
    {
        dicepath(n,i+j,osf+to_string(j)+"->");
    }
}
int main()
{
    dicepath(4,0,"");
    cout<<"\nTotal paths are: "<<totpath<<endl;
}