
#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(not swapped) break;
    }
}
int main()
{
    vector<int> v{5,6,2,6,9,0,-1};
    bubblesort(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}