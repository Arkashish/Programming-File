
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
int ternary(vector<int> &arr,int target)
{
    int l=0,r=arr.size()-1;
    while (l<=r)
    {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if(arr[m1]==target) return m1;
        if(arr[m2]==target) return m2;
        if (target<arr[m1])
        {
            r=m1-1;
        }
        else if(target>arr[m2])
        {
            l=m2+1;
        }
        else if(arr[m1]<target and arr[m2]>target)
        {
            l=m1+1;
            r=m2-1;
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
    vector<int> arr(n);   
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int target = 7;
    cout<<ternary(arr,target);
    
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}