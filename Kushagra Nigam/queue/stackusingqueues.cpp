
#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q;
    queue<int> q1;
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        while (q.size() != 1)
        {
            q1.push(q.front());
            q.pop();
        }
        int r = q.front();
        q.pop();
        while (q1.size() != 0)
        {
            q.push(q1.front());
            q1.pop();
        }
        return r;
    }

    /** Get the top element. */
    int top()
    {
        while (q.size() != 1)
        {
            q1.push(q.front());
            q.pop();
        }
        int r = q.front();
        //q.pop();
        q1.push(q.front());
        q.pop();
        while (q1.size() != 0)
        {
            q.push(q1.front());
            q1.pop();
        }
        return r;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    // MyStack myStack = new MyStack();
    // myStack.push(1);
    // myStack.push(2);
    // myStack.top();   // return 2
    // myStack.pop();   // return 2
    // myStack.empty(); // return False
    // int x = 1;
     MyStack* obj = new MyStack();
 obj->push(1);
 obj->push(2);
 int param_3 = obj->top();
 int param_2 = obj->pop();
 bool param_4 = obj->empty();
 cout<< param_2 << " " << param_3 << " " << param_4 << " ";
}