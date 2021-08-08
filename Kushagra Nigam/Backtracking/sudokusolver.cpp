
/*
Leetcode hatd problem
main function not included
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> ans;
    
    bool safe(int row,int col,char num,vector<vector<char>> &grid)
    {
        //check row
        for(int i=0;i<9;i++)
        {
            if(grid[row][i]==num)
                return false;
        }
        //check column
        for(int i=0;i<9;i++)
        {
            if(grid[i][col]==num)
                return false;
        }
        //check sub-grid
        int x = (row/3)*3;
        int y = (col/3)*3;
        
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(grid[i][j] == num)
                    return false;
            }
        }
        return true;
    }
    void fillSudoku(int row,int col,vector<vector<char>> &grid)//sudoku checker function
    {
        if(row==9)
        {
            ans = grid;
            return;
        }
        if(col==9)
        {
            fillSudoku(row+1,0,grid);
            return;
        }
        if(grid[row][col]!='.')
        {
            fillSudoku(row,col+1,grid);
            return;
        }
        for(int i='1';i<='9';i++)
        {
            if(safe(row,col,i,grid))
            {
                grid[row][col]=i;
                fillSudoku(row,col+1,grid);
                grid[row][col]='.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        fillSudoku(0,0,board);
        board=ans;
    }
};
