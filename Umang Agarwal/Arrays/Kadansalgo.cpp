#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int ar[n];
    cout<<"Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];
    }
    cout<<"\nThe array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
    int ans = ar[0];
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=ar[i];
        if(sum>ans)
        ans= sum;
        if(sum<0)
        sum=0;
    }
    cout<<"The sum is: " << ans<<"\n";
    
    
}