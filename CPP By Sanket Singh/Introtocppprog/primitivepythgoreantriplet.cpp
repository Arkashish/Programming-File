/*
You have been given a nnumber X. Yif(ou have to find the primitive pythagorean triplet for X as one of the sides eitheer base or  height. Make sure of the last point i.e. X is the base or hright i.e., it is not the heighest side.

X can be between the range of 5 <= X <= 10^9
Pythagoras theorem: a^2 + b^2 = c^2
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll x;
    cout<<"Enter the value of base or height: ";
    cin>>x;
    if(x%2==0)
    {
        //for even value of X
        cout << ((x*x)/4)-1 << " " << x << " " << ((x*x)/4)+1 <<endl;
    }
    else
    {
        //for odd value of x
        cout << x << " " << ((x*x)-1)/2 << " " << ((x*x)+1)/2 <<endl;
    }

}
