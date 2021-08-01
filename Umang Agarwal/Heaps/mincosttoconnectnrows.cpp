#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cin>>n;
    int ar[n];
    cout<<"\n"<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++)
        pq.push(ar[i]);
    
    int cost = 0;
    while(pq.size()>1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        cost+=x+y;
        pq.push(x+y);
    }
    cout<<"The cost is: "<<cost<<"\n";
    
    
    
	return 0;
}