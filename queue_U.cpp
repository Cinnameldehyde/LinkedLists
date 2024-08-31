#include <iostream>
using namespace std;

#define maxsize 5

int queue[maxsize], front = -1, rear = -1;

void Insert(int d){
    if(rear == maxsize - 1){
        cout << "overflow\n";
    }
    else{
        rear++;
        queue[rear] = d;
        if(front == -1){
            front++;
        }
    }
}

void Delete(){
    if(front == -1){
        cout << "empty\n";
    }
    else{
        int item = queue[front];
        if (front == rear){
            front = rear = -1;
            cout << "removed " << item << endl;
        }
        else{
            front++;
            cout << "removed " << item << endl;
        }
    }
}


void Traverse(){
    if(front == -1){
        cout << "empty\n";
    }
    else{
        for(int i  = front; i <= rear; i++){
            cout << queue[i] << " ";
        }
    }
}

int main(){
    Insert(5);
    Insert(3);
    Insert(7);
    Insert(9);
    Insert(2);
    Traverse();
    Delete();
    Traverse();
    return 0;
}