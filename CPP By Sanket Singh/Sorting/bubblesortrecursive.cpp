#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &v,int i,int n)
{
    if(n==1) return;
    if(i==n-1)
    {
        for(int j=0;j<v.size();j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<"\n";
        bubblesort(v,0,n-1);
        return;
    }
    
    if(v[i]>v[i+1])
        swap(v[i],v[i+1]);
    bubblesort(v,i+1,n);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    bubblesort(v,0,n);
    for(int j=0;j<v.size();j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<"\n";
    return 0;
}
// if(i<n)
//     {
//         bool swapped = false;
//         if(j<n-i-1)
//         {
//             if(v[j]>v[j+1])
//             {
//                 swap(v[j],v[j+1]);
//                 swapped = true;
//             }
//         }
//          if(not swapped) {
//           break;
//         }
//         else{
//             for(int k=0;k<n;k++)
//                 cout<<v[i]<<" ";
//             cout<<"\n";
//         }
        
//     }