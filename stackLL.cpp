#include <iostream>
using namespace std;

struct stack{
    int data;
    stack* next;

    stack(int d){
        this->data = d;
        this->next = NULL;
    }
};

stack *tos = NULL;


void Push(int d){
    stack *p = new stack(d);
    p->next = tos;
    tos = p;
}

void Pop(void){
    if(tos == NULL){
        cout << "Underflow\n";
    }
    else{
        int item = tos -> data;
        tos = tos->next;
        cout << "Popped " << item << endl;
    }
}

// same as SLL
void Traverse(void){
    if(tos == NULL){
        cout << "Empty\n";
    }
    else{
        stack* p = tos;
        while(p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main(void){
    Push(5);
    Push(65);
    Push(23);
    Push(53);
    Traverse();
    Pop();
    Pop();
    Traverse();
    return 0;
}