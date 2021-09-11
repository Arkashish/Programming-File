
//date - 6/04/2021
//problem link - https://www.spoj.com/problems/ANARC09A/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    string str;
    int count = 0;
    while(true)
    {
        cin>>str;
        if(str[0]=='-')
        {
            break;
        }
        stack<char> st;
        ll closing=0;//keeps the count of unbalanced braces
        ll ans=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='{')
                st.push('{');
            else{
                if(not st.empty()) // balancing the top
                    st.pop(); 
                else{
                    closing++;
                }
            }
        }
        if(st.size()>0)
        {
            if(st.size()%2!=0)
            {
                closing--;
                ans+=2;
            }
            ans+=st.size()/2;
        }
        if(closing>0)
            ans+=closing/2;
        cout<<++count<<" ."<<ans<<"\n";

    }
}