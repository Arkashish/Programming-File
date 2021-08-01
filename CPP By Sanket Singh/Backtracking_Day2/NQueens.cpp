#include<bits/stdc++.h>
using namespace std;
int count=0;

bool isItSafe(vector<vector<bool>> &grid,int row, int col, int n)
{
    //upper column
    for(int i=row-1;i>=0;i--)
    {
        if(grid[i][col])
        return false;
    }

    //left diagonal
    for(int i=row-1,j=col-1; i>=0 and j>=0;i--,j--)
    {
        if(grid[i][j])
        return false;
    }

    //right diagonal
    for(int i=row-1,j=col+1; i>=0 and j<n ;i--,j++)
    {
        if(grid[i][j])
        return false;
    }
    return true;
}

void display(vector<vector<bool>> &grid,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j])
            cout<<"Q ";
            else
            cout<<". ";
        }
        cout<<endl;
    }
    
}
void NQueens(vector<vector<bool>> &grid,int curr_row, int n)
{

    if(curr_row==n)
    {
        //count++;
        display(grid,n);
        cout<<"\n\n";
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(isItSafe(grid,curr_row,i,n))
        {
            grid[curr_row][i]=true;
            NQueens(grid,curr_row+1,n);
            grid[curr_row][i]=false;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<endl;
    vector<vector<bool>> grid(n, vector<bool> (n,false));

    NQueens(grid,0,n);
    //cout<<count<<endl;
}