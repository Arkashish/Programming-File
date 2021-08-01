
#include<bits/stdc++.h>
using namespace std;


void subset(int*arr, int i, int n, string osf)
{
    if(i==n)
    {
        cout<<"[ " << osf << "]"<<endl;
        return;
    }

    subset(arr,i+1,n,osf + to_string(arr[i])+ ",");
    subset(arr,i+1,n,osf);
}
int main()
{
    int n=3;
    int arr[]={1,2,3};
    subset(arr,0,n,"");
}