
#include<bits/stdc++.h>
using namespace std;

int squareroot(int n)
{
    int i=0;
    while(1)
    {
        if(pow(i,2)<=n && pow(i+1,2)>n)
        return i;
        i++;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Ente the value of n: ";
    cin>>n;
    int a = squareroot(n);
    cout<<"Sqaure Root value is: "<<a<<endl;
}