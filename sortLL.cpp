#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;

    Node(int d){
        this-> data=d;
    }
};

void insertAtHead(Node* &head, int d){

    // new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
};

void insertAtPosition(Node* &head, int position, int d){
    //inserting at first position
    if(position < 1){
        cout << "Invalid position.\n";
        return;
    }
    else if (position == 1) {
        insertAtHead(head, d);
    }

    Node* temp = head;
    int count = 1;
    Node* nodeToInsert = new Node(d);

    while (position-->1 && temp-> next != NULL){
        temp = temp->next;
    }

    //inserting at last position
    if (temp -> next == NULL) {
        temp -> next = nodeToInsert;
        return ;
    }
    //creating a node for d
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    return ;    
};

void print(Node* &head){
    Node* temp = head->next;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
};

Node* findMid(Node* &head){
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast -> next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* &left, Node* &right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node* answer = new Node(-1);
    Node* temp = answer;

    while(left != NULL && right != NULL){
        if(left-> data < right -> data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left!= NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right!= NULL){
        temp->next = right;
        temp = right;
        right = right -> next;
    }
    answer = answer -> next;
    return answer;
}

Node* mergeSort(Node* head){
    // base case
    if (head == NULL || head -> next == NULL){
        return head;
    }
    
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right halves
    Node* result = merge(left, right);
    return result;
}

int main(void){
    Node* node1 = new Node(5);
    Node* head = node1; 
    print(head);
    insertAtPosition(head, 2, 12);
    print(head);
    insertAtPosition(head, 3, 15);
    print(head);
    insertAtPosition(head, 4, 14);
    print(head);
    insertAtPosition(head, 5, 9);
    print(head);
    insertAtPosition(head, 6, 8);
    print(head);
    head = mergeSort(head);
    print(head);
    return 0;
}