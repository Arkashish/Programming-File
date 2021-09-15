
#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        int value = arr[i];
        while (j>=0 and value<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=value;
    }
}
int main()
{
    int n;
    vector<int> arr{7,8,9,-1,3,0,2,1};
    insertionsort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
}