
#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Inside A"
             << "\n";
    }
};

class B : public A
{
public:
    B()
    {
        cout << "Inside B"
             << "\n";
    }
};

class C : public A
{
public:
    C()
    {
        cout << "Inside C"
             << "\n";
    }
};

class D : public B,public C
{
public:
    D()
    {
        cout << "Inside D"
             << "\n";
    }
};

int main()
{
    D d();
}