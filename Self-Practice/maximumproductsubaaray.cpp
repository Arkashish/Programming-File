#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long maxDp[n],minDp[n];
        long ans=nums[0];
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                maxDp[i]=minDp[i]=nums[i];
            }else{
                if(nums[i]==0){
                    minDp[i]=maxDp[i]=0;
                }else{
                    minDp[i]=min((long)nums[i],min(nums[i]*maxDp[i+1],nums[i]*minDp[i+1]));
                    maxDp[i]=max((long)nums[i],max(nums[i]*maxDp[i+1],nums[i]*minDp[i+1]));
                }
            }
            ans=max(ans,maxDp[i]);
        }
        return ans;
    }
};
int main()
{
    Solution *ob = new Solution();
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<ob->maxProduct(nums)<<endl;

}