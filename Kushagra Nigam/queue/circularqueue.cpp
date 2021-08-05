

#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    
    vector<int> q;
    int n;
    int front = 0,rear = -1,size=0;
    MyCircularQueue(int k) {
        // q=q(k);
        n = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        else{
            // if(q.empty())
            // {
            //     front = rear =0;
            //     q[rear++] = value;
            // }
            // else{
                rear = (rear+1)%n;
                q[rear]=value;
            size++;
            // }
            return true;
        }   
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        else{
                //int a = q[front]; 
                front = (front+1)%n;
                // return a;
            size--;
            return true;
        }   
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        else
            return q[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return q[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        // if(q.size()==n)
        //     return true;
        // else
        //     return false;
        return size == n;
            
    }
};

int main()
{

    MyCircularQueue* obj = new MyCircularQueue(3);
    bool param_1 = obj->enQueue(1);
    bool param_2 = obj->enQueue(2);
    bool param_3 = obj->enQueue(3);
    bool param_4 = obj->enQueue(4);
    int param_5 = obj->Rear();
    bool param_6 = obj->isFull();
    bool param_7 = obj->deQueue();
    bool param_8 = obj->enQueue(4);
    int param_9 = obj->Front();
    bool param_10 = obj->isEmpty();
 cout<< param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " "  << param_5 << " " << param_6 << " " << param_7 << " " << param_8 << " " << param_9 << " " << param_10 << " ";
}
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */