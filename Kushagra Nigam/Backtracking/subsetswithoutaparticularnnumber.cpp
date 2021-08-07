
#include<bits/stdc++.h>
using namespace std;

void subsets(int *arr,vector<int> &temp,int i,int num,int n)
{
    if(i==n)
    {
       
        for(int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<< "\n";
        return;
        
    }
    if(temp[i]==num)//this throws an error because we are trying to accesss an index which is yet not allocated..since this is a vector and it is in uninitialised state
    {
        subsets(arr,temp,i+1,num,n);
    }
    else
    {
        temp.push_back(arr[i]);
        subsets(arr,temp,i+1,num,n);
        temp.pop_back();
        subsets(arr,temp,i+1,num,n);
    }
    
}
int main()
{
    int n,num;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> temp;
    int *arr = new int[n];
    cout<<"\n"<<"Enter the array contents: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n"<<"Enter the number to be ignored: ";
    cin>>num;
    subsets(arr,temp,0,num,n);

}