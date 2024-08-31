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

// Function to insert a new node at the end of the linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to check if the list is sorted in ascending order
bool isSorted(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        // A list with 0 or 1 node is always sorted
        return true;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->data > temp->next->data) {
            return false;  // List is not sorted
        }
        temp = temp->next;
    }

    return true;  // List is sorted
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter the number of elements in the list: ";
    cin >> n;

    // Insert random values into the linked list
    for (int i = 0; i < n; i++) {
        int value;
        cout << "enter valuE: ";
        cin >> value;  // Random values between 0 and 99
        insert(head, value);
    }

    cout << "Linked List: ";
    display(head);

    // Check if the list is sorted
    if (isSorted(head)) {
        cout << "The list is sorted." << endl;
    } else {
        cout << "The list is not sorted." << endl;
    }

    return 0;
}
