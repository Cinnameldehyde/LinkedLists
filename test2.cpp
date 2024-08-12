#include <iostream>
using namespace std;

// Node structure with a constructor
struct Node {
    int data;
    Node* next;

    // Constructor to initialize the node
    Node(int value) : data(value), next(nullptr) {}
};

// Function to create a circular linked list with n nodes and user-defined values
Node* createCircularLinkedList(int n) {
    if (n < 1) return nullptr;

    int value;
    cout << "Enter the value for node 1: ";
    cin >> value;

    Node* head = new Node(value); // Creating the first node
    Node* temp = head;

    for (int i = 2; i <= n; ++i) {
        cout << "Enter the value for node " << i << ": ";
        cin >> value;

        temp->next = new Node(value); // Creating and linking the next node
        temp = temp->next;
    }

    temp->next = head;  // Making the list circular

    return head;
}

// Function to display the sum of the first m nodes
void displaySum(Node* head, int n, int m) {
    if (!head) return;

    Node* temp = head;
    int sum = 0;

    for (int i = 0; i < m; ++i) {
        sum += temp->data;
        temp = temp->next;  // Move to the next node
    }

    cout << "Sum of the first " << m << " nodes: " << sum << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n > 3): ";
    cin >> n;

    if (n <= 3) {
        cout << "Number of nodes should be greater than 3!" << endl;
        return 0;
    }

    Node* head = createCircularLinkedList(n);

    cout << "Enter the value of m: ";
    cin >> m;

    displaySum(head, n, m);

    return 0;
}
