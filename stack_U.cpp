#include <iostream>
using namespace std;

const int maxsize = 5;
int stack[maxsize],tos=-1;
void push(int item){
    if(tos== maxsize-1)
{
    cout<<"overflow\n";
}
else{
    tos++;
    stack[tos]=item;
}

}
void pop(void)
{
    int item =  0;
    if(tos== -1)
    {
        cout<<"underflow\n";

    }
    else{
        item=  stack[tos];
        tos--;
        cout<<"popped"<<item<<endl;

    }
}
void travers(void)
{
    int i;
    if(tos== -1){
        cout<<"empty stack\n";
        return;

    }
    for(i= tos;i>=0;i--)
    {cout<<stack[i]<<" ";}
}

int  main()
{
    push(6);
    push(5);
    push(4);
    push(3);
    pop();
    pop();
    travers();

    return 0;



}
