
// Question link:  https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1 or n==0)
            return n;
        int i=1,j=1;
        while(i<n)
        {
            if(nums[i]==nums[i-1])
                i++;
            else
            {
                nums[j]=nums[i];
                i++;j++;
            }
        }
        return j;
} 
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<removeDuplicates(v)<<"\n";
}