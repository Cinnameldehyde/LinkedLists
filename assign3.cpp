#include <iostream>
using namespace std;


struct Node{
public:
    int data;
    Node* next;
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    ~Node(){
         int value = this -> data;
        //memory free krr rhe hain
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtTail(Node* &head, int d){
    Node* temp = new Node(d);
    if (head == nullptr)
        head = temp;
    Node* last = head;

    // Traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    // Change the next pointer of the last node to point to the new node
    last->next = temp;
}

void Print(Node* &head){
    Node* temp = head;

    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void Search(Node* &head){
    int s, check = 0, index = 0;
    Node* temp = head;
    cout << "Enter element to search: ";
    cin >> s;
    while(temp != nullptr){
        if(temp -> data == s){
            check++;
            break;
        }
        else
            temp = temp->next;
        index++;
    }
    if(check == 0){
        insertAtTail(head, s);
        cout << "Not found. Updated LL = \n";
        Print(head);}
    else
        cout << "Found at " << index << endl;
}

void insertPos(Node** current, int pos, int data)
{
    // This condition to check whether the
    // position given is valid or not.
    if (pos < 1)
        cout << "Invalid position!" << endl;
    else {

        // Keep looping until the pos is zero
        while (pos--) {

            if (pos == 0) {

                // adding Node at required position
                Node* temp = new Node(data);

                // Making the new Node to point to 
                // the old Node at the same position
                temp->next = *current;

                // Changing the pointer of the Node previous 
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
              // Assign double pointer variable to point to the 
              // pointer pointing to the address of next Node 
              current = &(*current)->next;
        }
    }
}

void Delete(Node* &head){
    int i;
    Node* temp = head;
    cout << "Enter position to delete: ";
    cin >> i;
    if(i == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;

    }

    else {
        // deleting any middle node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt <= i) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    cout << "Updated LL = \n";
        Print(head);
}

int main(void){
    Node* head;
    Node* tail = head;
    int i, d;
    cout << "Enter number of elements: ";
    cin >> i;
    for(int n = 0; n < i; n++){
        cout << "Enter data: ";
        cin >> d;
        insertAtTail(tail, d);
    }
    Print(head->next);
    Search(head->next);
    Delete(head->next);
    insertPos(&head, 2, 68);
    Print(head->next);
    return 0;
}



