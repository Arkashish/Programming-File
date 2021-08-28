
//check this running for sample test cases but showing error on submmission
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> &v,int start,int end,int t)
{
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(v[mid] == t)
        {
            return mid+1;
        }
        if(v[mid]>t)
        end=mid-1;
        else
        start = mid+1;
    }
    return start;
}
int main()
{
    int n;
    cin>>n;
    while(n!=0){
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int c = 0;
    for(int i=0;i<n;i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int x = v[i]+v[j];
            int sum = binarysearch(v,i,n-1,x);
            c+=n-sum;
        }
    }
    cout<<c<<"\n";
    cin>>n;
    }
}