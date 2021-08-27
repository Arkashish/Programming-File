

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int count_ = 0;
bool checkspecial(int a ,int b)
{
    double sq = sqrt(a+b);
    return (sq-floor(sq))==0;
}
void helper(vector<ll> &arr,int start)
{
    if(start>1 and (!checkspecial(arr[start-2],arr[start-1]))) //if the first 2 nos dont make a perfect square then its no use compairing the rest
    {
        return;
    }
    if(start==arr.size()-1 and (!checkspecial(arr[start],arr[start-1]))) //check for last element
    {
        return;
    }
    if(start == arr.size())
    {
        count_++;
    }
    unordered_set<ll> mp;
    for (int i = start; i < arr.size(); i++)
    {
        if(mp.count(arr[i])==0)
        {
            mp.insert(arr[i]);
            swap(arr[i],arr[start]);
            helper(arr,start+1);
            swap(arr[i],arr[start]);
        }
    }
    
}
int noofspecialperm(vector<ll> &v)
{
    helper(v,0);
    return count_;
}
int main()
{
    int n;
    cin>>n;
    vector<ll> v(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    cout<<noofspecialperm(v)<<"\n";
}


//output:
// n =3 , v = {1,17,8}
// output - 2