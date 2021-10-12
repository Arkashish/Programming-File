
//Program finds only the integer part of square root of a number
//self made code
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//self made code
int squarerootofnum(int n)
{
    int lo=1,hi=(n/2);
    int target,val;
    // cin>>target;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(mid*mid<=n)
        {
            val = mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    // cout<<val<<endl;
    return val;
}
//sirs version
int squareroot(int n)
{
    int lo=1,hi=n-1;
    int ans = -1;
    while(lo<=hi)
    {
        int m = lo + (hi-lo)/2;
        if(m*m == n)
        return m;
        else if(m*m>n)
        {
            hi=m-1;
        }
        else
        {
            ans = m;
            lo=m+1;
        }
    }
    return ans;
}
int main() {
	
	int n;
	cin>>n;
// 	for(int i=1;i*i<=(n/2);i++)
    cout<<"Sir's version ans: "<<squareroot(n)<<"\nSelf made version: "<<squarerootofnum(n)<<endl;
    
	return 0;
}
