#include <iostream>
using namespace std;

struct queue{
    int data;
    queue* next;

    queue(int d){
        this->data = d;
        this->next = NULL;
    }
};

queue *front = NULL;
queue *rear = NULL;


// like insertAtTail in SLL
void Insert(int d){
    queue *p = new queue(d);
    if(front == NULL){
        front = rear = p;
    }
    else{
        rear->next = p;
        rear = p;
    }
}

void Delete(void){
    if(front == NULL){
        cout << "Underflow\n";
    }
    else{
        queue* p = front;
        int item = p -> data;
        // condition: only one element in queue
        if(front == rear){
            // similar to front = rear = -1;
            front = rear = NULL;
        }
        else{
            // similar to front++;
            front = front->next;
        }
        cout << "Popped " << item << endl;
    }
}

// same as SLL
void Traverse(void){
    if(front == NULL){
        cout << "Empty\n";
    }
    else{
        queue* p = front;
        while(p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main(void){
    Insert(5);
    Insert(65);
    Insert(23);
    Insert(53);
    Traverse();
    Delete();
    Delete();
    Traverse();
    return 0;
}