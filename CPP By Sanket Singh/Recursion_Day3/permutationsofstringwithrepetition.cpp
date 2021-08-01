
#include<bits/stdc++.h>
using namespace std;

void permutation(string str, string perm)
{
    //base case
    if(str.size()==0)
    {
        cout<<perm<<endl;
        return;
    }

    unordered_set<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(s.count(ch)==0)
        {
            string ros = str.substr(0,i) + str.substr(i+1);
            permutation(ros,perm+ch);
            s.insert(ch);
        }
    }
    
}   

int main()
{
    permutation("AABB","");
}