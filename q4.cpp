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

// Function to search for a value 'x' in the list
Node* search(Node* head, int x) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    do {
        if (temp->data == x) {
            return temp;  // Return the node containing value x
        }
        temp = temp->next;
    } while (temp != head);

    return nullptr;  // Value not found
}

// Function to make the last node point to the node containing value x
void updateLastNode(Node*& head, Node* xNode) {
    if (head == nullptr || xNode == nullptr) {
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // 'temp' is now the last node, update its next to xNode
    temp->next = xNode;
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

int main() {
    Node* head = nullptr;
    int n, x;

    cout << "Enter the number of nodes (n > 3): ";
    cin >> n;

    // Insert 'n' values into the circular linked list
    for (int i = 1; i <= n; i++) {
        insert(head, i * 10);  // Insert multiples of 10 for simplicity
    }

    cout << "Circular Linked List: ";
    display(head);

    cout << "Enter the value to search (x): ";
    cin >> x;

    // Search for the value x in the list
    Node* xNode = search(head, x);

    if (xNode != nullptr) {
        cout << "Value " << x << " found in the list." << endl;
        // Update the last node to point to the node containing value x
        updateLastNode(head, xNode);

        cout << "Updated Circular Linked List: ";
        display(head);
    } else {
        cout << "Value " << x << " not found in the list." << endl;
    }

    return 0;
}
