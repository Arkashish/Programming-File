
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("");

    while (!q.empty())
    {
        string x = q.front();
        q.pop();

        if (x.length() == n)
        {
            cout << x << " ";
            continue;
        }

        q.push(x + '0');
        q.push(x + '1');
    }
}