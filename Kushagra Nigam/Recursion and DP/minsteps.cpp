

/*
You are given a number n. Your job is to reduce the number to 0 by reducing it with n/3 iif divisible by 3 and reduce it by n/2 if divisible by 2 else just reduce it by 1. Find min steps to get 0
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int fun(int n)
{
    if(n==0)
    return 0;
    
    if(n%3==0)
    return 1+fun(n/3);
    
    if(n%2==0)
    return 1+fun(n/2);
    
    return 1+fun(n-1);
    
}
int main() {
    cout<<fun(10)<<endl;
	return 0;
}
