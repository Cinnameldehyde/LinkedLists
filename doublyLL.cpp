#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int d){
        this->data = d;
    }

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        //for representation purpose
        cout << "Memory free for node with data : " << val << endl;
    }
};

void Print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp -> next;
    }
    cout << endl; 
}

int getLength(Node*head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}

void insertAtHead(Node* &head, int d){
    if(head == NULL){ //empty list
        Node* temp = new Node(d);
        head = temp;
    }
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, int d){
    Node* temp = new Node(d);
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr -> next;
    }
    temp -> prev = curr;
    curr -> next = temp;
}

void insertAtPos(Node* &head, int d, int pos){
    if (pos == 1){
        insertAtHead(head, d);
        return;
    }
    Node* curr = head;
    while(pos-- >> 1 && curr->next != NULL){
        curr = curr -> next;
    }

    if (curr -> next == NULL){
        insertAtTail(head, d);
        return;
     }
    
    Node* temp = new Node(d);
    temp -> next = curr -> next;
    curr->next->prev = temp;
    curr -> next = temp;
    temp -> prev = curr;
    
}

void deleteNode(Node* &head, int pos){
    if(pos == 1){
        //first node
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = head -> next;
        temp->next = NULL;
        delete temp;
    }
        else{
            // middle or last node
            Node* curr = head;
            Node* prev = curr;
            while (pos -- > 1){
                prev = curr;
                curr = curr -> next;
            }
            curr -> prev = NULL;
            prev -> next = curr -> next;
            curr -> next = NULL;
            // current both side is NULL now

            delete curr;
        }

}

int main(void){
    Node* node1 = new Node(5);
    Node* head = node1;
    Print(head);
    cout << "length = " << getLength(head) << endl;
    cout << head << " : head ";

    //insertAtHead(head, 10);
    //Print(head);
    //cout << "length = " << getLength(head) << endl;
    //    cout << head << " : head ";

    insertAtTail(head, 25);
    Print(head);
    cout << "length = " << getLength(head) << endl;
        cout << head << " : head ";
        insertAtTail(head, 50);
    Print(head);
    cout << "length = " << getLength(head) << endl;
        cout << head << " : head ";
        insertAtTail(head, 70);
    Print(head);
    cout << "length = " << getLength(head) << endl;
        cout << head << " : head ";

    insertAtPos(head, 9, 6);
    Print(head);
    cout << "length = " << getLength(head) << endl;
    cout <<endl<< &head << " : head " << endl;
    return 0;
 }