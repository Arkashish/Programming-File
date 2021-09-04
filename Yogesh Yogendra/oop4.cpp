
#include<bits/stdc++.h>
using namespace std;

class ADD{
    public:
        int sum(int a)  
        {
            return a+a;
        }
        int sum(int a,int b)
        {
            return a+b;
        }
        double sum(double a , double b)
        {
            return a+b;
        }

};
int main()
{
    ADD a;
    cout<<a.sum(10)<<"\n";
    cout<<a.sum(10,20)<<"\n";
    cout<<a.sum(10.0,27.0)<<"\n";
}