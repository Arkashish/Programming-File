
#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int profit[], int w, int n)
{
    //base case
    if (w == 0 || n == 0)
        return 0;

    if (w < wt[n-1])
    {
        return knapsack(wt, profit, w, n - 1);
    }
    else
    {
        return max(profit[n-1] + knapsack(wt, profit, w - wt[n-1], n - 1), knapsack(wt, profit, w, n - 1));
    }
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(wt, val, W, n);
    return 0;
}