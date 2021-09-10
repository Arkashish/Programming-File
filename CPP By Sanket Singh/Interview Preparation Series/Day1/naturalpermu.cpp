

#include<bits/stdc++.h>
using namespace std;

vector<int> largestpermu(vector<int> &arr,int k)
{
    int n = arr.size();
    int maxEl = *max_element(arr.begin(),arr.end());
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]=i;
    int pos = 0;
    for(int i= maxEl;i>=1;i--)
    {
        if(k==0) break;
        if(mp.count(i))
        {
            int temp = mp[i];
            if(temp == pos)
            {
                pos++;
                continue;
            }
            arr[temp] = arr[pos];
            mp[arr[temp]] = temp;
            arr[pos] = i;
            mp[i] = pos;
            k--;
            pos++;
        }
    }
    return arr;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> result = largestpermu(arr,k);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<"\n";

}
