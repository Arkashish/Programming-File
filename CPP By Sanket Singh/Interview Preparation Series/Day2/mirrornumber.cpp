//asked in google
#include<bits/stdc++.h>
using namespace std;

vector<string> mirror(int n,int size)
{
    if(n==0)
    return {""};
    if(n==1)
    return {"0","1","8"};

    //recursive task
    vector<string> temp=mirror(n-2,size);
    vector<string> result;
    for(string s: temp)
    {
        if(n!=size)
        {
            result.push_back("0"+s+"0");
        }
        result.push_back("1"+s+"1");
        result.push_back("6"+s+"9");
        result.push_back("8"+s+"8");
        result.push_back("9"+s+"6");
    }
    return result;
}
int main()
{
    vector<string> v=mirror(3,3);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<< " ";
    cout<<"\n";
}