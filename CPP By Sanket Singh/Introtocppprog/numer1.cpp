/*
You are given an array of integers where every digit is repeated except one digit.Find that digit.

*/

#include<bits/stdc++.h>
#include "add.h"
using namespace std;

int main()
{
    int n;
    cout<<"ntr the value of n:";
    cin>>n;
    cout<<endl;
    int ar[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int x = 0;
    for(int i=0;i<n;i++)
    {
        x=x^ar[i];
    }
    cout<<"The unique element is: "<<x<<endl;

    

}