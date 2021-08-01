#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
	int copy = n;
	vector<int> ar;
	while(copy>0){
	   //  int d = copy%10;
	     ar.push_back(copy%10);
	     copy/=10;
	}
	for(int i=0;i<ar.size();i++)
	    cout<<ar[i]<<" ";
	    cout<<"\n";
	int c = ar.size();
	int b [c],k=0;
	for(int i=c-1;i>=0;i--)
	{
	    b[k++]=ar[i];
	}
	for(int i=0;i<ar.size();i++)
	    cout<<b[i]<<" ";
	    cout<<"\n";
	int count = 1;
	vector<int> v;
	for(int i=1;i<c;i++)
	{
	    if(b[i]==b[i-1])
	    count++;
	    else
	    {
	        v.push_back(count);
	        v.push_back(b[i-1]);
	        //i--;
	        count = 1;
	    }
	}
	
 	if(b[c-1]!=b[c-2])
 	{
	    v.push_back(count);
	    v.push_back(b[c-1]);
 	}
 	if(b[c-1]==b[c-2])
 	{
 	    v.push_back(count);
 	    v.push_back(b[c-1]);
 	}
	
	for(int i=0;i<v.size();i++)
	    cout<<v[i]<<" ";
	return 0;
}