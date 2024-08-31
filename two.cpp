#include <iostream>
using namespace std;
const int maxsize = 5;
int stack[maxsize], tos = -1;
void push(int item)
{
    if (tos == maxsize - 1)
    {
        cout << "overflow\n";
    }
    else
    {
        tos++;
        stack[tos] = item;
    }
}
void pop(void)
{

    int item = 0;
    if (tos == -1)
    {
        cout << "underflow\n";
    }
    else
    {
        item = stack[tos];
        tos--;

        // tos=stack[item];
        cout << "popped " << item << endl;
    }
}
void travers(void)
{
    if (tos == -1)
    {
        cout << "underflow\n";
        return;
    }
    for (int i = 0; i <= tos; i++)
    {
        cout << stack[i] << " ";
    }

}

int main()
{
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    travers();
    return 0;
}