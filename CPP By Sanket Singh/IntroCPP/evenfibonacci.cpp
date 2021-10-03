
//Program to print only the even fibonacci uptil n without touching the odd numbers
 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ef1=2;
    int ef2=8;
    int efi=ef2;
    cout<<ef1<<endl;
    while(efi<=n)
    {
        cout<<efi<<endl;
        efi=(4*ef2)+ef1;
        ef1=ef2;
        ef2=efi;
    }
}