
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef struct Node node;
node *head = NULL;
node *newnode;
node* createll(int val)
{
    newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else{
        node *q = head;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next = newnode;
    }
    return head;
}
node* sort()
{
    node *curr=head,*nextval=head;
    while(curr!=NULL)
    {
        if(curr->data!=1)
        {
            swap(curr->data,nextval->data);
            nextval=nextval->next;
        }
        curr=curr->next;
    }
    return head;
}

void display()
{
    node *q= head;
    while (q!=NULL)
    {
        cout<<q->data<<"->";
        q=q->next;
    }
    cout<<"\n";
    
}
int main()
{
    createll(1);
    createll(0);
    createll(0);
    createll(1);
    createll(1);
    createll(1);
    createll(1);
    createll(0);
    createll(1);
    createll(0);
    display();
    sort();
    display();

}