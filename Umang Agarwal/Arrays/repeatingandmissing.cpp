#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int ar[n];
    cout<<"Enter the array elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin>>ar[i];
    }
    cout<<"\nThe array elements are: ";
    int max = ar[0];

    for (int i = 1; i <= n; i++)
    {
        if(ar[i]>=max)
        max = ar[i];
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
    int hash[n];
    for (int i = 1; i <= n; i++)
    {
        hash[i]=0;
    }
    for (int i = 1; i <= n; i++)
    {
        //cout<<"ntr loop"<<endl;
        hash[ar[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        //cout<<"ntr loop"<<endl;
        cout<<hash[i]<<" ";
    }
    cout<<"\n";
    for (int i = 1; i <= n; i++)
    {
        //cout<<"ntr llop"<<endl;
        if(hash[i]>1)
        cout<<"The repeated number is: "<<i<<endl;

        if(hash[i]==0)
        cout<<"The missing number is: "<< i <<endl;
    }
    
}