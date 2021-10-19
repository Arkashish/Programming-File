
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	// your code goes here
	string s;
	cin>>s;
	int c=0;
	for(int i=0;s[i]!='\0';i++)
	{
	    if(s[i]=='(')
	        c++;
	    else if(s[i]==')')
	        c--;
	    else if(c<0)
	        break;
	}
	if(c==0)
	cout<<"balanced";
	else if(c>0 or c<0)
	    cout<<"Unbalanced";
	return 0;
}
