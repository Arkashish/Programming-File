

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    //sorting in ascending order
    sort(v.begin(),v.end()); //O( NlogN)
    for(auto it: v)
        cout<<it<<" ";
        cout<<"\n";

    int sum = accumulate(v.begin(),v.end(),0LL);
    cout<<"\n Sum: "<<sum;

    reverse(v.begin(),v.end());//O(N)
    cout<<"\n Reverse array: ";
    for(auto it: v)
        cout<<it<<" ";

    //We can also sort in reverse(descending) order by using the following  function: 
    sort(v.begin(),v.end(),greater<int>());

    //count the number of elements in an array
    int x;
    cin>>x;
    int c = count(v.begin(),v.end(),x);

    if(find(v.begin(),v.end(),x)!=v.end())
    {
        cout<<"X is present";
    }

    cout<<binary_search(v.begin(),v.end(),x);
    next_permutation(v.begin(),v.end());
    prev_permutation(v.begin(),v.end());

}