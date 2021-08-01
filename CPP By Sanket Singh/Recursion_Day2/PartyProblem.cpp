

#include<iostream>
using namespace std;

int f(int n)
{
    //base case
    if(n==1)
    return 1;
    if(n==2)
    return 2;

    return f(n-1)+(n-1)*f(n-2);
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<f(n)<<endl;
}