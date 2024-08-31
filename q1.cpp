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

// Function to insert a new node at the end of the list
void insertAtTail(Node*& head, int value) {
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

// Function to find the position till the list is sorted
int findSortedPosition(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or has only one element, it's sorted till the first element
        return 0;
    }

    int index = 1;
    Node* current = head;

    while (current->next != nullptr && current->data <= current->next->data) {
        index++;
        current = current->next;
    }
    
    return index; // The index of the last node where the list is sorted
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
    int value;
    cout << "Inserting values:" << endl;
    // Insert the first half of the list in sorted order
    for (int i = 0; i < n; i++) {
        cout << "enter value " << i << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    cout << "\nLinked List: ";
    display(head);

    // Find the position till the list is sorted
    int sortedPosition = findSortedPosition(head);

    cout << "The list is sorted till position: " << sortedPosition << endl;

    return 0;
}
