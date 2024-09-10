#include<iostream>
using namespace std ;

struct node{
    int data ;
    node*next;
    node(int d){
        
    
    data=d;
    next=NULL;
}
};
void insertAthead(node* &head,node* &tail,int d)
{
    node*p=new node(d);
    if(head==NULL){
        head=p;
        tail=p;
    }
    else{
               p->next=head;
               head=p;

    }
    
}

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
void print(node* &head,node* &tail)

{
          node*p=head;
          while( p!=NULL)
          {
            cout<<p->data<<" ";
            p=p->next;

          }

}
void insertAtposition(node* &head,int pos,int d)
{
    if(pos<1)
    {
        cout<<"invalid ";

    }
    node**current= &head;
    while(pos-- >1)

    {
     current=&(*current)->next;
    }
    node*p=new node(d);
    p->next=*current;
    *current=p;
    
}

int length(node* &head){
 int i = 0;
 node* p = head;
 while(p!= NULL){
    i++;
    p=p->next;
 }
 return i;
}
int main()
{
node*head=NULL;
node*tail=NULL;
insertAthead(head,tail,5);
insertAthead(head,tail,4);
insertAthead(head,tail,3);
insertAthead(head,tail,2);
print(head,tail);

cout << "\n" << "\n";
insertAtposition(head,3,15);
print(head,tail);
cout << "\n length is : " << length(head);
return 0;



}


    

