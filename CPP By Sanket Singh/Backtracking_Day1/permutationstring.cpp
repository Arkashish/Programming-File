

//For unique elements i.e. no overhead carry used
#include<bits/stdc++.h>
using namespace std;

void permutation(string str,int j)
{
    if(str.size()-1==j)
    {
        cout<<str<<endl;
        return;
    }
 
    for(int i=j;i<str.size();i++)
    {
        swap(str[i],str[j]);
        permutation(str,j+1);
        swap(str[i],str[j]);
    }
}
int main()
{
    permutation("ABC",0);
}