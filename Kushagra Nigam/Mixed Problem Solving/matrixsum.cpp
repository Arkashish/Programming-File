
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int i=0,j=0,sum=0;
        while(i<r and j<c )
        {
            sum+=mat[i][j];
            i++;
            j++;
        }
        i=0;
        j=c-1;
        while(i<r and j>=0 )
        {
            if( i!=j)
                sum+=mat[i][j];
            i++;
            j--;
        }
        return sum;
    }
    int diagonalSum1(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int sum=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if((i+j)==r-1 and mat[i][j]!=INT_MIN){
                    sum+= mat[i][j];
                    mat[i][j] = INT_MIN;
                }
                    
                else if(i==j and mat[i][j]!=INT_MIN)
                {
                    sum+=mat[i][j];
                    mat[i][j] = INT_MIN;
                }
            }
        }
        return sum;
        
    }
    int diagonalSum2(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int sum=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if((i+j)==r-1 and mat[i][j]!=INT_MIN){
                    sum+= mat[i][j];
                    mat[i][j] = INT_MIN;
                }
                    
                else if(i==j and mat[i][j]!=INT_MIN)
                {
                    sum+=mat[i][j];
                    mat[i][j] = INT_MIN;
                }
            }
        }
        return sum;
        
    }
};