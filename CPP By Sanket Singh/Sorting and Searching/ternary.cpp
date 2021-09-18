
#include<bits/stdc++.h>
using namespace std;
int ternary(vector<int> &arr,int target)
{
    int lo=0,hi=arr.size()-1;
    while(lo<=hi)
    {
        int m1 = lo+(hi-lo)/3;
        int m2 = hi-(hi-lo)/3;
        if(arr[m1] == target) return m1;
        if(arr[m2]==target) return m2;
        if(arr[m1]>target)
        {
            hi=m1-1;
        }
        else if(arr[m2]<target)
        {
            lo=m2+1;
        }
        else{
            hi=m2-1;
            lo=m1+1;
        }
    }
    return -1;
}
int main()
{
    vector<int> v{1,2,3,4,5,6,7,8};
    int t;
    cin>>t;
    cout<<ternary(v,t);
}