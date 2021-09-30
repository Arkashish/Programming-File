#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

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

void countingsort(vector<int> &arr)
{
    int val = *max_element(arr.begin(),arr.end());
    vector<int> freq(val+1,0);

    for (int &el: arr)
    {
        freq[el]++;
    }
    for(int i=1;i<=val;i++)
    {
        freq[i]+=freq[i-1];
    }
    vector<int> output(arr.size());
    for(int i = arr.size()-1;i>=0;i--)
    {
        output[freq[arr[i]]-1] = arr[i];
        freq[arr[i]]--;
    }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     arr[i] = output[i];
    // }
    arr = output;
}
int main()
{
    clock_t begin = clock();
    file_io();

    vector<int> arr;
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    countingsort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<< " ";
    }
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}