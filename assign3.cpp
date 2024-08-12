#include <iostream>
#include <vector>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
    ~Node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete next;
            this->next = nullptr;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtTail(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    Node *last = head;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = temp;
}

void Print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Search(Node *&head)
{
    int s;
    vector<int> index_vec;
    Node *temp = head;
    cout << "Enter element to search: ";
    cin >> s;

    int index = 1;
    while (temp != nullptr)
    {
        if (temp->data == s)
        {
            index_vec.push_back(index);
        }
        temp = temp->next;
        index++;
    }

    if (index_vec.empty())
    {
        insertAtTail(head, s);
        cout << "Not found. Updated LL = \n";
        Print(head);
    }
    else
    {
        cout << "Found at ";
        for (int idx : index_vec)
        {
            cout << idx << " ";
        }
        cout << endl;
    }
}

void insertPos(Node *&head, int pos, int data)
{
    if (pos < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    Node **current = &head;
    while (pos-- > 1)
    {
        if (*current == nullptr)
        {
            cout << "Position exceeds list length!" << endl;
            return;
        }
        current = &(*current)->next;
    }
    Node *temp = new Node(data);
    temp->next = *current;
    *current = temp;
}

void Delete(Node *&head)
{
    int i;
    cout << "Enter position to delete: ";
    cin >> i;
    if (i < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (i == 1)
    {
        Node *temp = head;
        if (head)
        {
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
    }
    else
    {
        Node *curr = head;
        Node *prev = nullptr;
        int cnt = 1;
        while (curr != nullptr && cnt < i)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr != nullptr)
        {
            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;
        }
        else
        {
            cout << "Position exceeds list length!" << endl;
        }
    }
    cout << "Updated LL = \n";
    Print(head);
}

int main()
{
    Node *head = nullptr;
    int i, d;
    cout << "Enter number of elements: ";
    cin >> i;
    for (int n = 0; n < i; n++)
    {
        cout << "Enter data: ";
        cin >> d;
        insertAtTail(head, d);
    }
    Print(head);
    Search(head);
    Delete(head);
    insertPos(head, 2, 68);
    Print(head);
    return 0;
}
