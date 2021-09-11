
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
void file_io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    clock_t begin = clock();
    file_io();

    char ch;
    queue<char> q;
    unordered_map<char, int> mp;
    while (true)
    {
        cout << "Enter the next character "
             << "\n";
        cin >> ch;
        if(ch=='0')
            break;
        if (mp.count(ch) == 0)
        {
            //entry is not present
            mp[ch] = 1;
            q.push(ch);
        }
        else
        {
            mp[ch] += 1;
        }
        while (not q.empty() and mp[q.front()] != 1)
            q.pop();
            if (not q.empty())
                cout << q.front() <<"\n";
            else
                cout << "-1\n";
        
    }

    
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
    return 0;
}
