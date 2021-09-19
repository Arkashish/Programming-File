
#include<bits/stdc++.h>
using namespace std;
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

class DLLNode{
public:
    int key,value;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int key,int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
unordered_map<int,DLLNode*> cache;
int size;
int capacity = 0;
DLLNode *head = new DLLNode(-1,-1);
DLLNode *tail = new DLLNode(-1,-1);
void addNodeatHead(DLLNode *node)
{
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    return ;
}
void removenode(DLLNode *node)
{
    DLLNode *prev = node->prev;
    DLLNode *next = node->next;
    prev->next = next;
    next->prev = prev;
}
int removenodefromtail() //DLLNode *tail
{
    DLLNode *temp = tail->prev;
    //tail->prev->next = NULL;
    removenode(temp);
    return temp->key;
}
//this movetohead() is reqd to implement the caching
void movetohead(DLLNode *node) //DLLNode *head,
{
    cout<<"Accessed the key "<< node->key << "\n";
    removenode(node);
    addNodeatHead(node);
}
int get(int k)
{
    if(cache.count(k) == 0)
    {
        cout<<"Value is not present at cache pls insert it first\n ";
        return INT_MIN;
    }
    DLLNode *node = cache[k];
    movetohead(node);
    return node->value;
}
void put(int k,int v)
{
    if(cache.count(k)==0)
    {
        DLLNode *node = new DLLNode(k,v);
        cache[k] = node;
        cout<<"Added a new key "<<k<<"\n";
        addNodeatHead(node);
        capacity++;
        if(capacity>size)
        {
            int removekey = removenodefromtail();
            cout<<"As the cache is full we need to remove "<< removekey <<"\n";
            cache.erase(removekey);
            capacity--;
        }
    }
    else
    {
        DLLNode *node = cache[k];
        node->value = v;
        movetohead(node);
    }
    
}
int main()
{
    clock_t begin = clock();
    file_io();

    
    cout<<"Please enter the size of cache: ";
    cin>>size;
    cout<<"\n Size of cache is "<<size <<"\n";
    head->next = tail;
    tail->prev = head;

    int q;
    cin>>q;
    while (q--)
    {
        char ch;
        cin>>ch;
        int k,v;
        if(ch=='p')
        {
            cin>>k>>v;
            put(k,v);
        }
        else
        {
            cin>>k;
            int value = get(k);
            cout<<"Value for key " << k << " is " << value <<endl;
        }
        
    }
    

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n"
         << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC << "ms \n";
    #endif
    return 0;
}