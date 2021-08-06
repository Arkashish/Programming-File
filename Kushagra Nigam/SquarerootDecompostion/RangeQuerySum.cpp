
#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n,b,sz;
    vector<int> B,arr;
    NumArray(vector<int>& nums) {
        
        n=nums.size();
        b=sqrt(n);
        sz=(n+b-1)/b;
        
        B.assign(sz,0);
        for(int i=0;i<n;i++)
        {
            B[i/b] += nums[i];
        }
        arr=nums;
    }
    
    void update(int index, int val) {
        B[index/b] += val - arr[index];
        arr[index] = val;
    }
    
    int sumRange(int l, int r) {
        int sum = 0;
        int LB = l/b;
        int RB = r/b;
        
        if(LB==RB)
        {
            for(int i=l;i<=r;i++)
                sum+=arr[i];
            return sum;
        }
        
        int LB_end = LB*b + b-1;
        
        for(int i = l;i <= LB_end;i++)
        {
            sum+=arr[i];
        }
        
        int RB_start = RB*b;
        for(int i=RB_start;i<=r;i++)
        {
            sum+=arr[i];
        }
        
        for(int i = LB+1 ;i<=RB-1;i++)
        {
            sum+=B[i];
        }
        return sum;
        
    }
};


int main()
{
    //check the main function(not printing the values)
    int n;
    vector<int> nums;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"\n"<<"Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    
    NumArray* obj = new NumArray(nums);
    int param_2 = obj->sumRange(0, 2);
    cout<<"\n"<<param_2<<" \n";
    obj->update(1, 2);
    int param_3 = obj->sumRange(0, 2);
    cout<<"\n"<<param_2<<" "<<param_3;
}