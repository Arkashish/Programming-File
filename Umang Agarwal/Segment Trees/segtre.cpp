#include<bits/stdc++.h>
using namespace std;

int st[400005];

void build(int x,int lx,int rx,int ar[],int n)
{
    if(rx-lx==1)
    {
        if(lx<n)
        st[x] = ar[lx];
        return;
    }
    int mid = (lx+rx)>>1;
    build(x*2 + 1,lx,mid,ar,n);
    build(x*2 + 2,mid,rx,ar,n);

    st[x] = st[2*x + 1] + st[2*x + 2];
    return;
}
void solve()
{
    int n;
    n=8;
    int ar[] = {3,1,2,5,6,4,3,2};
    build(0,0,n,ar,n);
    for(int i=0;i<15;i++)
    {
        cout<<st[i]<<" ";
    }
    
}
int main()
{
    
    // cout<<"Enter the size of the tree";
    // cin>>n;
    // int ar[n];
    // cout<<"\nEnter the array elements: ";
    // for(int i=0;i<n;i++)
    // {
    //     cin>>ar[i];
    // }
    solve();
}