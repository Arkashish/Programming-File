
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define loop(i,a,b) for(int i = (a); i <= (b); i++)
#define revloop(i,a,b) for(int i = (b); i >= (a); i--)
#define pb push_back
#define ump unordered_map
#define dec2bin(n) std::bitset<8>(n).to_string()
#define str2int(n) std::stoi(n)
#define bin2dec(n) std::stoi(bin, nullptr, 2)
#define numofdigits(n,b) ((int)(log(n)/log(b)) + 1)
int reversDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
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
    cout<<"Welcome to Arkashish's Template";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
#endif
}