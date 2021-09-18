
#include <bits/stdc++.h>
using namespace std;
int bin_search(vector<int> &arr, int target, int lo, int hi)
{
    if (lo <= hi)
    {
        int mid = lo+(hi-lo)/2;
        //cout<<mid<<"\n";
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
        {
            return bin_search(arr, target, mid+1,hi);
        }
        else
            return bin_search(arr, target, lo, mid-1);
    }
    return -1;
}
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    int t;
    cin >> t;
    cout << bin_search(v, t, 0, v.size() - 1);
}