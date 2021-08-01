

#include<iostream>
using namespace std;

int value(int n)
{
    if(n==1)
    return 2;
    if(n==2)
    return 3;

    return value(n-1)+value(n-2);
}

int main()
{
    int n;
    cout<<"Enter the vaalue of n: ";
    cin>>n;
    cout<<value(n)<<endl;
}