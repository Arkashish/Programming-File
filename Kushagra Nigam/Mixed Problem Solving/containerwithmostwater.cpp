
//Leetcode 11

#include <bits/stdc++.h>
using namespace std;

int maxheight(vector<int> &height)
{
    int n = height.size();
    int i = 0, j = n - 1;
    int maxh = INT_MIN;
    while (i < j)
    {
        maxh = max(maxh, (j - i) * min(height[i], height[j]));
        if (height[j] > height[i])
            i++;
        else
        {
            j--;
        }
    }
    return maxh;
}
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << maxheight(height);
}