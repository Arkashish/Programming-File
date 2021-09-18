
//date - 6/05/2021

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int lo,int hi)
{
    int index= lo;
    int pivot = hi;
    for(int i=lo;i<hi;i++)
    {
        if(arr[i]<arr[pivot])
        {
            swap(arr[i],arr[index]);
            index++;
        }
    }
    swap(arr[pivot],arr[index]);
    return index;
}

int randpivot(vector<int> &arr,int lo,int hi)
{
    int n = rand();
    int pivot = lo + (n%(hi-lo+1));
    swap(arr[pivot],arr[hi]);    
    return partition(arr,lo,hi);
}
void Quicksort(vector<int> &arr,int lo,int hi)
{
    if(lo<hi)
    {
        int pivot_index = randpivot(arr,lo,hi);
        Quicksort(arr,lo,pivot_index-1);
        Quicksort(arr,pivot_index+1,hi);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}