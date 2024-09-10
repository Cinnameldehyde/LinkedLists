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


// like insertAtTail in CLL
// Insert
void enQueue(int d){
    queue *p = new queue(d);
    if(front == NULL){
        front = rear = p;
    }
    else{
        rear->next = p;
        rear = p;
        
    }
    rear -> next = front;
}

void deQueue(void){
    if(front == NULL){
        cout << "Underflow\n";
    }
    else{

        int item = front -> data;
        // condition: only one element in queue
        if(front == rear){
            // similar to front = rear = -1;
            front = rear = NULL;
        }
        else{
            // similar to front++;
            // temp to clear data;
            queue* temp = front;
            front = front->next;
            temp->data = NULL;
        }
        cout << "Popped " << item << endl;
    }
}

// same as CLL
void Traverse(void){
    if(front == NULL){
        cout << "Empty\n";
    }
    else{
        queue* p = front;
        do{
            cout << p->data << " ";
            p = p->next;
        }while(p != front);
        cout << endl;
    }
}

int main(void){
    enQueue(5);
    enQueue(65);
    enQueue(23);
    enQueue(53);
    Traverse();
    deQueue();
    deQueue();
    Traverse();
    return 0;
}