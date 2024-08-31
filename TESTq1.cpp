// CPP code to find the pair with given sum
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	Node* next;
    Node(d){
        data = d;
        next = NULL;
    }
};

/* Given a reference (pointer to pointer)
	to the head of a list and an int,
	push a new node on the front 
	of the list. */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = 
		(struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Takes head pointer of the linked list and sum*/
int check_pair_sum(struct Node* head, int sum)
{
	struct Node* p = head, *q;
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

/* Driver program to test above function */
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Use push() to construct linked list*/
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);
	push(&head, 18);
	push(&head, 47);
	push(&head, 16);
	push(&head, 12);
	push(&head, 14);

	/* function to print the result*/
	bool res = check_pair_sum(head, 26);
	if (res == false)
		cout << "NO PAIR EXIST";

	return 0;
}
