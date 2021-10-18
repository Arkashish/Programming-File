
#include<bits/stdc++.h>
using namespace std;

int longestsubarraywithsumk(int *arr,int n,int k)
{
    unordered_map<int,int> mp;
    int prefixsum = 0;//manages to create the prefix sumaaray
    int result = 0;//this stores the final lonest sum subarray
    for(int i=0;i<n;i++)
    {
        prefixsum+=arr[i];
        if(prefixsum==k)
        {
            result = max(result,i+1);
        }
        if(mp.count(prefixsum-k)>0)
        {
            result=max(result,i-mp[prefixsum-k]);
        }
        mp[prefixsum] = min(i,mp[prefixsum]);

    }
    return result;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<longestsubarraywithsumk(arr,n,k)<<endl;
}