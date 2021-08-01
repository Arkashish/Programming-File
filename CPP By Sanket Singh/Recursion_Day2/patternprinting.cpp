

#include<iostream>
using namespace std;

void pattern(int n,int i)
{
    if(n==0)
    return;
    if(i<n)
    {
        cout<<"* ";
        pattern(n,i+1);
    }
    else{
        cout<<endl;
        pattern(n-1,0);
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    pattern(n,0);
}