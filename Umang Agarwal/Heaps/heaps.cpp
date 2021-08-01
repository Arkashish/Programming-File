#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int n,k;
    cout<<"Enter the value of n and k: ";
    cin>>n>>k;
    int ar[n];
    cout<<endl<<"Enter the array elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];
    }

    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(ar[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    cout<<"The "<< k << "th smallest element is: " <<pq.top()<<endl;
    
}