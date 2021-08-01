
#include<bits/stdc++.h>
using namespace std;
// #define logarr(arr,b,c)  for(int z=(a);z<=(b);z++) cout<<arr[z];

void setbacktrack(int *arr,vector<int> &temp,int i, int n)
{
    if(i==n)
    {
        if(temp.size()>0)
        {
            // logarr(temp,0,temp.size()-1);
            for(int i=0;i<temp.size();i++)
            {
                cout<<temp[i]<<"";
            }
            cout<<"\n";
            return;
        }
    }

    temp.push_back(arr[i]);
    setbacktrack(arr,temp,i+1,n);
    temp.pop_back();
    setbacktrack(arr,temp,i+1,n);
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> temp;
    setbacktrack(arr,temp,0,n);
}