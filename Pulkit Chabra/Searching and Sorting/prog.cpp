
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin>>n;
        vector<int> v(n);
        for(int &i: v)
        {
            cin>>i;
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += i*v[i] ,ans -=(n-i-1)*v[i];
        }
        cout<<ans<<"\n";
 
}