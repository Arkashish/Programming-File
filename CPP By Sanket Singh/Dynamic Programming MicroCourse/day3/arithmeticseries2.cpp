
//Problem link - https://unacademy.com/class/problem-solving-on-dynamic-programming-3/3NIL4F4C

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 0;
        vector<unordered_map<ll,ll>> dp(n);
        int ans = 0;
        ll diff = (ll)((ll)arr[1]-(ll)arr[0]);//this is the base setup
        dp[1][diff] = 1;
        for(int i=2;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                diff = (ll)((ll)arr[i] - (ll)arr[j]);
                if(dp[j].count(diff))
                {
                    dp[i][diff] += dp[j][diff] +1;
                    ans+=dp[j][diff];
                }
                else
                {
                   dp[i][diff] +=1;
                    
                }
            }
        }
        return (int)ans;
    }
    
};