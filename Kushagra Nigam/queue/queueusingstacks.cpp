
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
    stack<int> st1;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(st.size()!=1)
        {
            st1.push(st.top());
            st.pop();
        }
        int r = st.top();
        st.pop();
        while(st1.size()!=0)
        {
            st.push(st1.top());
            st1.pop();
        }
        return r;
    }
    
    /** Get the front element. */
    int peek() {
        while(st.size()!=1)
        {
            st1.push(st.top());
            st.pop();
        }
        int r = st.top();
        st1.push(st.top());
        st.pop();
        while(st1.size()!=0)
        {
            st.push(st1.top());
            st1.pop();
        }
        return r;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
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
     MyQueue* obj = new MyQueue();
 obj->push(1);
 obj->push(2);
 int param_3 = obj->peek();
 int param_2 = obj->pop();
 bool param_4 = obj->empty();
 cout<< param_2 << " " << param_3 << " " << param_4 << " ";
}