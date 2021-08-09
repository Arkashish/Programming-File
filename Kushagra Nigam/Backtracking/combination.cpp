/*
Leetcode class function included after the main function
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> temp;
void combination(int n,int k,int idx)
{
    if(temp.size()==k)
    {
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<endl;
        return;
    }

    for(int i=idx;i<=n;i++)
    {
        temp.push_back(i);
        combination(n,k,i+1);
        temp.pop_back();
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    if(k>n)
    {
        cout<<"Not possible. Value of k needs to be smaller than or at max equal to n"<<endl;
        return 0;
    }
    combination(n,k,1);
    
}



// Here you go with the leetcode solution

// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> temp;
//     void combination(int n,int k,int idx)
//     {
//         if(temp.size()==k)
//         {
//             ans.push_back(temp);
//             return;
//         }
        
//         for(int i=idx;i<=n;i++)
//         {
//             temp.push_back(i);
//             combination(n,k,i+1);
//             temp.pop_back();
//         }
//     }
//     vector<vector<int>> combine(int n, int k) {
//         combination(n,k,1);
//         return ans;
//     }
// };