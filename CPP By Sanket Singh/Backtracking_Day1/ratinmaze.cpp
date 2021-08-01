#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int totalpaths=0;

bool isitsafe(int i,int j,int n,vector<vector<bool>> &visited)
{
    return i<n and j<n and i>=0 and j>=0 and visited[i][j]==false;
}
void helper(int i,int j,int n,vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    //base case1
    if(i==n-1 and j==n-1)
    {
        totalpaths++;
        return;
    }
    
    //base case2
    if(not isitsafe(i,j,n,visited))
        return;
        
    //recrusive and self work;
    visited[i][j]=  true;
    
    if(i+1<n and grid[i+1][j]==0)//down
        helper(i+1,j,n,grid,visited);
    
    if(j+1<n and grid[i][j+1]==0)//right
        helper(i,j+1,n,grid,visited);
        
    if(j-1 >= 0 and grid[i][j-1]==0)//left
        helper(i,j-1,n,grid,visited);
        
    if(i-1>=0 and grid[i-1][j]==0)//up
        helper(i-1,j,n,grid,visited);
        
    visited[i][j] = false;
    return;
}

int countratmaze(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    
    helper(0,0,n,grid,visited);
    return totalpaths;
}
    
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<vector<int>> grid(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>grid[i][j];
	    }
	}
	cout<<countratmaze(grid);
	return 0;
}
