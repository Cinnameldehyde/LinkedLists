#include<iostream>
using namespace std ;
struct node
{
    int data ;
    node*next;
    node(int d)
    {
    data =d;
    next=NULL;
    }
};
void insertAthead(node* &head,node* &tail, int d)
{
    if( head==NULL){
        node*p=new node(d);
        head=p;
        tail=p;

    }
    else{
       node*p=new node(d);
        p->next=head;
        head=p;

    }
}

void insertAttail(node* &head,node* &tail, int d)
{
    if( head==NULL){
        node*p=new node(d);
        head=p;
        tail=p;

    }
    else{
       node*p=new node(d);
        
        tail->next=p;
        tail=p;
    }
}

void checkSort(node* &head) {
    if (head == NULL || head->next == NULL) {
        cout << "LIST NOT VALID.\n";
        return ;
    }
    int index = 1;
    node* current = head;
    while (current->next != NULL) {
        if(current->data > current->next->data){
            cout << "LIST NOT SORTED.\n";
            return ;
        }

        current = current->next;
    }
    cout << "LIST SORTED.\n";
}

void print(node* & head)
{ 
    node*p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;

    }
    cout<<endl;
    }
int main( )
{
    node*head=NULL;
    node*tail=NULL;

    // insertAthead(head,tail,5);
    // insertAthead(head,tail,4);
    // insertAthead(head,tail,3);
    // insertAthead(head,tail,2);

    int n, val;
    cout << "enter n: ";
    cin >> n;
    for(int i = 0;i < n; i++){
        cout << "enter value: ";
        cin >> val;
        insertAthead(head,tail,val);
    }
print(head);
checkSort(head);
return 0;

}