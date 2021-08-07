
/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/
#include<bits/stdc++.h>
using namespace std;

void check(int *arr,vector<int> &sum,int i,int n,int target)
{
    if(i==n)
    {
        if(target == 0){
            //cout<<"\nPrinting result: ";
        for(int j=0;j<sum.size();j++)
            cout<<sum[j]<<" ";
        cout<<"\n";
        }
        return;
    }

    if(arr[i]<=target)
    {
        sum.push_back(arr[i]);
        check(arr,sum,i,n,target-arr[i]);//using the same element in the next iteration
        sum.pop_back();
    }
    check(arr,sum,i+1,n,target);
    return;
}

int main()
{
    int n,target;
    cin>>n>>target;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> sum;
    check(arr,sum,0,n,target);
    
}