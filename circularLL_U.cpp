#include<iostream>
using namespace std;

struct node{
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;

    }
};
void print(node* &head)
{
    node*p=head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
void insertAtpos(node* &head,int pos,int d)
{

    node*p= new node(d);
    if(pos<1)
    {
        cout<<"invalid";
    }
    else{
        node**current=  &head;
        while(pos-->1)
        {
            current=&(*current)->next;
        }
        p->next=*current;
        *current =p;
    }
}

void insertNode(node* &head, int find, int d){
    node* p = new node(d);
    if(head == NULL){
        head = p;
        p -> next = p;
    }

    else{
        node* current = head;
        while(current->data != find){
            current = current -> next;
        }
        p->next = current -> next;
        current -> next = p;
    }
}

