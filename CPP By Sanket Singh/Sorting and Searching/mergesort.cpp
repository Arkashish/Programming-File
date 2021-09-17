
#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int start,int mid , int end)
{
    int temp[end-start+1];
    int i = start,j=mid+1,k=0;
    while(i<=mid and j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++,k++;
        }
        else{
            temp[k] = arr[j];
            j++,k++;
        }
    }
    while (i<=mid)
    {
        temp[k] = arr[i];
        i++,k++;
    }
    while (j<=end)
    {
        temp[k] = arr[j];
        j++,k++;
    }
    for(int i= start;i<=end;i++)
    {
        arr[i] = temp[i-start];
    }
}
void merge_sort(int *arr,int start,int end)
{
    if(start<end)
    {
        int mid = start + (end-start)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}