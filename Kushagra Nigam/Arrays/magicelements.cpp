
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    int nums,c=0;
	    for(int i=0;i<n;i++)
	    {
	        if(sum-arr[i]<(arr[i]+k))
	            c++;
	    }
	    
	    cout<<c<<"\n";
	}
	return 0;
}
