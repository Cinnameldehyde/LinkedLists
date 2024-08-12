#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

void insertPartiallySorted(Node*& head, int n) {
    if (n <= 0) return;

    std::srand(std::time(0));  // Seed for random number generation

    // Create the head of the list
    head = new Node(std::rand() % 100);
    Node* current = head;

    // Insert partially sorted values
    for (int i = 1; i < n; ++i) {
        int value = std::rand() % 100;
        if (value >= current->data) {
            current->next = new Node(value);
        } else {
            current->next = new Node(std::rand() % 100);
        }
        current = current->next;
    }
}

int findPartiallySortedStart(Node* head) {
    if (!head) return -1;

    int pos = 0;
    Node* current = head;

    while (current->next) {
        if (current->data > current->next->data) {
            return pos + 1;
        }
        current = current->next;
        pos++;
    }
    return pos + 1; // The entire list is sorted
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int n = 10;  // Number of nodes in the list

    insertPartiallySorted(head, n);
    printList(head);

    int pos = findPartiallySortedStart(head);
    std::cout << "The partially sorted sequence starts at position: " << pos << std::endl;

    return 0;
}
