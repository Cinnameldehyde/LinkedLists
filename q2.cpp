#include <iostream>
using namespace std;

// Node structure
class Node {
    public:
    int data;
    Node* next = NULL;

    Node(int d){
        this->data = d;
    }
};

// Function to insert a new node at the end of the circular linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;  // Point to itself, making it circular
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;  // Complete the circle
    }
}

// Function to display the sum of the first 'm' nodes
int sumFirstMNodes(Node* head, int m) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return 0;
    }

    int sum = 0;
    Node* temp = head;
    for (int i = 0; i < m; i++) {
        sum += temp->data;
        temp = temp->next;

        // If we cycle through the list, just continue traversing
        if (temp == head && i < m - 1) {
            cout << "List is being cycled to sum " << m << " nodes." << endl;
        }
    }
    
    return sum;
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    while (temp != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "back to head" << endl;
}

int main() {
    Node* head = nullptr;
    int n, m;

    cout << "Enter the number of nodes (n > 3): ";
    cin >> n;

    // Insert 'n' random values into the circular linked list
    for (int i = 1; i <= n; i++) {
        insert(head, i * 10);  // Insert multiples of 10 for simplicity
    }

    cout << "Circular Linked List: ";
    display(head);

    cout << "Enter the value of m to sum the first m nodes: ";
    cin >> m;

    int sum = sumFirstMNodes(head, m);

    cout << "Sum of the first " << m << " nodes is: " << sum << endl;

    return 0;
}
