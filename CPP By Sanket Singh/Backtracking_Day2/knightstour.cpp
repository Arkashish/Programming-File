#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isItSafe(vector<vector<int>> &grid, int n, int i, int j, vector<vector<bool>> &visited)
{
    return i >= 0 and j >= 0 and i < n and j < n and visited[i][j] == false;
}

void knightstour(vector<vector<int>> &grid, int n, int i, int j, int count, vector<vector<bool>> &visited)
{
    //base case
    if (count == n * n - 1)
    {
        grid[i][j] = count;
        display(grid, n);
        cout << "\n\n";
        return;
    }
    if (count >= n * n)
        return;

    int xdir[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
    int ydir[8] = {1, -1, 2, -2, 1, -1, 2, -2};
    visited[i][j] = true;
    grid[i][j] = count;
    for (int k = 0; k < 8; k++)
    {
        if (isItSafe(grid, n, i + xdir[k], j + ydir[k], visited))
        {
            //grid[i][j]=++count;
            knightstour(grid, n, i + xdir[k], j + ydir[k], count + 1, visited);
        }
    }
    grid[i][j] = -1;
    visited[i][j] = false;
}
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << endl;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    knightstour(grid, n, 0, 0, 0, visited);
}