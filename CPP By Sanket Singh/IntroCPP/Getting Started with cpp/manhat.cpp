
//April 8/04/21
// https://www.codechef.com/problems/MOSTDIST

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


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

    ll q;
    cin>>q;
    ll ans=0,count = 1;
    bool* visited = new bool[500005]();
    priority_queue<pair<ll,ll>> p1,p2,p3,p4;
    while (q--)
    {
        char ch;
        cin>>ch;
        if(ch=='+')
        {
            ll x,y;
            cin>>x>>y;
            x=x^ans;
            y=y^ans;
            p1.push({x+y,count});
            p2.push({x-y,count});
            p3.push({-x+y,count});
            p4.push({-x-y,count});
            count++;
        }
        else if (ch=='-')
        {
            ll n;
            cin>>n;
            n=n^ans;
            visited[n]=true;

        }
        else
        {
            ll x,y;
            cin>>x>>y;
            x=x^ans;
            y=y^ans;
            ll res= INT_MIN;
            while(not p1.empty() and visited[p1.top().second]) p1.pop();
            while(not p2.empty() and visited[p2.top().second]) p2.pop();
            while(not p3.empty() and visited[p3.top().second]) p3.pop();
            while(not p4.empty() and visited[p4.top().second]) p4.pop();
            if(not p1.empty()){
                res = max(res,p1.top().first -(x+y));
            }
            if(not p2.empty()){
                res = max(res,p2.top().first -(x-y));
            }
            if(not p3.empty()){
                res = max(res,p3.top().first -(-x+y));
            }
            if(not p4.empty()){
                res = max(res,p4.top().first -(-x-y));
            }
            cout<<res<<"\n";
            ans = res;
        }
        
    }
    
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
    return 0;

}
