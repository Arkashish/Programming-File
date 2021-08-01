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
    
    for (int i = 0; i < n; i++)
    {
        int x=ar[i]^ar[i+1];
        if(x==0)
            cout<<"Repeating number is: "<<ar[i]<<endl;
    }
    
}