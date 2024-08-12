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
};

void Print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp -> next;
    }
}

int main(void){
    Node* node1 = new Node(5);
    
}