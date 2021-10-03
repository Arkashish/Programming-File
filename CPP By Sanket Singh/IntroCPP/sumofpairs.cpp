//Question- Given n positive numbers we need to return the sum of products of all the possible nC2 pairs from the given n number:
//1,2,3
//(1*2)+(2*3)+(1*3) = 11
#include <bits/stdc++.h>
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

    int n;cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int sum=0,sqsum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ar[i];
        sqsum+=(ar[i]*ar[i]);
    }
    cout<<sum<<" "<<sqsum<<"\n";
    cout<<((sum*sum)-sqsum)/2<<endl;
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}