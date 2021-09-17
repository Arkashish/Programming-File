

#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector<int> &arr,int target)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==target)
            return i;
    }
    return -1; // no index was found havinng target value
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int target;
    cin>>target;
    cout<<linearsearch(v,target)<<"\n";

}