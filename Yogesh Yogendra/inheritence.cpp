
#include<bits/stdc++.h>
using namespace std;

class B{
    public: //remeber by default it remains private
    B(){
        cout<<"B is called"<<"\n";
    }
};
class C{
    public:
    C()
    {
        cout<<"C is called"<<"\n";
    }
};
class A:public B,public C{
    public:
    A(){
        cout<<"A is called"<<"\n";
    }
};
int main()
{
    cout<<"PRograM StarTed";
    A a();
}