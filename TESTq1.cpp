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

/* Takes head pointer of the linked list and sum*/
int check_pair_sum(node* head, int sum)
{
	node* p = head, *q;
	while (p != NULL) {
	
		q = p->next;
		while (q != NULL) {

		// check if both sum is equal to
		// given sum
		if ((p->data) + (q->data) == sum) {
			cout << p->data << " " << q->data;
			return true;
		}	 
		q = q->next;		 
		}

		p = p->next;
	}

	return 0;
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
/* function to print the result*/

	if (check_pair_sum(head, 7) == false)
		cout << "NO PAIR EXIST";
    else
        cout << "Pair Exist\n";
return 0;



}


    




