
#include<bits/stdc++.h>
using namespace std;

void permutation(string str,string perm)
{
    //base case
    if(str.size()==0)
    {
        cout<<perm<<endl;
        return;
    }

    for(int i=0;i<str.size();i++)
    {
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        permutation(ros,perm+ch);

    }
}
int main()
{
    // this problem can handle only unique characters.
    permutation("ABC","");
}
