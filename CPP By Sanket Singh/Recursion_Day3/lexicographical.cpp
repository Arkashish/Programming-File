
#include<bits/stdc++.h>
using namespace std;

void lexico(int n,int i)
{
    //base case
    if(n<i)
    return;
    //clock_t;

    cout<<i<<endl;
    for(int j=(i==0)?1:0;j<=9;j++)
    {
        lexico(n,10*i+j);
    }
}
int main()
{
    int n;
    cout<<"Enter the value oif n: ";
    cin>>n;
    cout<<"\n";
    clock_t t;
    double time_taken;
    t = clock();
    lexico(n,0);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    cout<<"\nTime taken: "<<time_taken<<endl;
}