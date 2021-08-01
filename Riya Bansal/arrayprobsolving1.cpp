
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int ar[n];
    cout<<"\nEnter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int left[n],right[n];
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]*ar[i-1];
    }
    for(int i = n-2;i>=0;i--)
    {
        right[i] = right[i+1]*ar[i+1];
    }
    cout<<"Left array: ";
    for(int i=0;i<n;i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<"\n";
    cout<<"Right array: ";
    for(int i=0;i<n;i++)
    {
        cout<<right[i]<<" ";
    }
    cout<<"\n";

    int c[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = left[i]*right[i];
    }
    cout<<"The array after all multiplications is: ";
    for(int i=0;i<n;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<"\n";

    

}