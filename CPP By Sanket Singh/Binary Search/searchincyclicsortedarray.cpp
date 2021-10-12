
//Date - 10/01/21
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define MAX(x,y) (x>y)?x:y
#define MIN(x,y) (x<y)?x:y
void file_io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int binarysearch(int *arr,int n,int target)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]>target)
            hi = mid-1;
        else
            lo=mid+1;
    }
    return -1;
}
int binarysearchonrotatedarray(int *arr,int n,int target)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]>=arr[lo]){
            //case1
            if(target>=arr[lo] and target<=arr[mid])
                hi = mid-1;
            else
            {
                lo = mid+1;
            }
        }
        else{
            if(target>=arr[mid] and target<=arr[hi])
                lo = mid+1;
                
            else
            {
                hi = mid-1;
            }
        }
            
    }
    return -1;
}
int main()
{
    clock_t begin = clock();
    file_io();
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<binarysearchonrotatedarray(arr,n,target)<<endl;
    
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}