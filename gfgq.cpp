#include<iostream>
using namespace std;
struct node {
    int data ;
    node*next;
    node(int d){
        data  =d;
        next=NULL;

    }
};

void insertAttail(node* &head,node* &tail,int d)
{
    node*p=new node(d);
    if(head==NULL){
        head=p;
        tail=p;
    }
    else{
        tail->next=p;
        tail=p;



    }
    
}

void find(node* &head)
{
    int i=1,mid;
    node*p=head;
    while(p!=NULL)
    {
        p=p->next;
        i++;
        
    }
    if(i%2==0)
    {
   mid=i/2;

    }
    else{
        i++;
        mid=i/2;
    }
    p=head;
    for(int i=1;i<mid;i++)
    {
         p=p->next;
         
    }
    cout<<p->data<<"is mid node ";

}

void count (node* &head,int key)
{
    node*p=head;
    int count = 0;
    while(p!= NULL){
        if(p->data == key){
            count++;
        }
        p = p->next;
    }

    cout << "count = " << count;
}

int main ()
{
    node* head = NULL;
    node* tail = NULL;
    insertAttail(head, tail, 5);
    insertAttail(head, tail, 6);
    insertAttail(head, tail, 7);
    insertAttail(head, tail, 5);
    insertAttail(head, tail, 9);

    find(head);
    count(head,5);
    return 0;
}
