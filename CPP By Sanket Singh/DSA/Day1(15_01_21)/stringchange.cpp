
#include<bits/stdc++.h>
using namespace std;

void casepermu(string inp,string oup,vector<string> &v)
{
    //base case
    if(inp.size()==0)
    {
        v.push_back(oup);
        return;
    }
    string ros = inp.substr(1);
    if(inp[0]>='a' and inp[0]<='z')
    {
        //small case letter
        casepermu(ros,oup+inp[0],v);
        casepermu(ros,oup+(char)(inp[0]-32),v);
    }
    else if (inp[0]>='A' and inp[0]<='Z')
    {
        //upper case letter
        casepermu(ros,oup+inp[0],v);
        casepermu(ros,oup+(char)(inp[0]+32),v);
    }
    else
    {
        //numeric
        casepermu(ros,oup+inp[0],v);
    }    
}
int main()
{
    string str = "1aB3";
    vector<string> v;
    casepermu(str,"",v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //another method of printing
    for(string s : v)
    {
        cout<<s<<" ";
    }

}