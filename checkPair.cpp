#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
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

void print(node* &head,node* &tail)

{
          node*p=head;
          while( p!=NULL)
          {
            cout<<p->data<<" ";
            p=p->next;

          }

}

int length(node* &head){
    node* p = head;
    int i=1;
    while(p!= NULL){
        i++;
        p=p->next;
    }
    return i;
}

void checkPairSum(node* &head, int sum){
    //int a = 0, b = 0;
    node* a = head;
    node* b = head->next;
        while(a!=NULL){
            while(b!=NULL){
                if(a->data + b-> data == sum){
                    cout << "Pair found (" << a->data << "," << b->data << ")\n";
                    break;
                }
                b = b->next;
            }
            b = a->next;
            a = a->next;
        }
    return;
}

int main()
{
node*head=NULL;
node*tail=NULL;
insertAttail(head,tail,5);
insertAttail(head,tail,4);
insertAttail(head,tail,3);
insertAttail(head,tail,2);
print(head,tail);

cout << "\n" << "\n";
checkPairSum(head, 9);
return 0;
}