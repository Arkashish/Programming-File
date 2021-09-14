
//Given a number a 1<= a,n <=10^9 Find the last 5 digits of a^n

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll a,ll n)
{
    if(n==0)
    return 1;
    
    if(n%2==0)
    {
        return power(a*a,n/2);
    }
    else
        return a*power(a*a,(n-1)/2);
}
int main() {
	// your code goes here
    ll a,n;
    cin>>a>>n;
    cout<<power(a,n)%(100000)<<"\n";
	return 0;
}
