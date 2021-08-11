
//ASKED IN MICROSOFT
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
   // Node(int x) : data(x), next(NULL) {}
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

node* partionlist(int B)
{
    node* c1=NULL;
    node* c2=NULL;
    node *l1=c1;
    node *l2=c2;
    node* tmp = head;

    while(tmp!=NULL)
    {
        if(tmp->data<B)
        {
            if(c1==NULL)
            {
                c1=new node();
                c1->data = tmp->data;
                c1->next=NULL;
                l1=c1;
            }
            else
            {
                l1->next = new node();
                l1->data = tmp->data;
                l1=l1->next;
                //l1->next=NULL;
            }
        }
        else
        {
            if(c2==NULL)
            {
                c2=new node();
                c2->data = tmp->data;
                c2->next=NULL;
                l2=c2;
            }
            else
            {
                l2->next= new node();
                l2->data = tmp->data;
                l2=l2->next;
                //l2->next=NULL;
            }
        }
        node* x=tmp;
        tmp = tmp->next;
        free(x);
        head=tmp;
    }
    if(c1==NULL) return c2;
    l1->next = c2;
    head = c1;
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
    createll(4);
    createll(3);
    createll(2);
    createll(5);
    createll(2);
    // createll(1);
    // createll(0);
    // createll(1);
    // createll(0);
    display();
     partionlist(3);
    display();

}