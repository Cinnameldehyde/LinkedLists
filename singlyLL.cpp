#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if (this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed with value: " << value << endl ;
    }
};

void insertAtHead(Node* &head, int d){

    // new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
};

//tail pointer of Node type that indicate endpoint of list
void insertAtTail(Node* &tail, int d){
    // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
};

void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    //inserting at first position
    if (position == 1) {
        insertAtHead(head, d);
    }

    Node* temp = head;
    int count = 1;

    while (count < position -1 ){
        temp = temp->next;
        count++;
    }

    //inserting at last position
    if (temp -> next == NULL) {
        insertAtTail(tail, d);
        return ;
    }
    //creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

    
};

void deleteNode(int position,Node* &head){

    //deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        // now to free memory of start node
        temp->next = NULL;
        delete temp; 
    }

    // deleting middle or last node
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while (count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev ->next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

// traversing a LL
void print(Node* &head){
    Node* temp = head;
    while( temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
};

int main(void){
    Node* node1 = new Node(5);
    //cout << node1 -> data << endl;
    //cout << node1 -> next << endl;
    Node* head = node1; 
    print(head);
    //insertAtHead(head, 12);
    //insertAtHead(head, 15);
    Node* tail = node1;
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail, head, 2, 14);
    print(head);
    cout << "head " << head -> data << endl; 
    cout << "tail " << tail -> data << endl;

    deleteNode(4, head);
    print(head);

    cout << "head " << head -> data << endl; 
    cout << "tail " << tail -> data << endl;
    return 0; 
}