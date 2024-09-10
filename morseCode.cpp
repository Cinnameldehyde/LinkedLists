#include <iostream>
#include <malloc.h>
#include <string.h>
#include <cstring>
#include <windows.h>
#include <iomanip>
#include <cmath>

using namespace std;

struct node
{
    char letter;
    struct node *left;
    struct node *right;
};

struct node *createNode(char letter)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->letter = letter;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void traversal(string str, int n, node* head)
{
    node* ptr = head;
    int j = 0;
    for(int i=0; i<=n; i++){
            if(str[i] == '.'){
                ptr = ptr->left;
    }
    else if(str[i] == '-'){
            ptr = ptr->right;
    }
    else if(str[i] == ' ' || str[i] == '\0'){
            cout<<ptr->letter;
    ptr = head;
    }
    }
}

class Node
{
public:
    char data;
    Node *next;
};

Node *head = NULL;

void addnode(char n)
{
    Node *newnode = new Node;
    newnode->data = n;
    newnode->next = NULL;
    if (head == NULL)
        {
            head = newnode;
    }
    else
        {
            Node *ptr = head;
    while (ptr->next != NULL)
        {
            ptr = ptr->next;
    }
    ptr->next = newnode;
    }
}


void intro()
{ 
    system("color 0a");
    string str = " DATA STRUCTURES LAB ";
    string str2 = " PROJECT (PBL) ";
    cout<< "\n\n\n\t\t\t\t\t--------------------------------------------" <<endl;
    cout<< "\t\t\t\t\t\t";
    for (int i = 0; i<str.length(); i++)
        {
            Sleep(50);
    cout<< str[i];
    }
    cout<< "\n\t\t\t\t\t\t ";
    for (int i = 0; i< str2.length(); i++)
        {
            Sleep(100);
    cout<< str2[i];
    }
    cout<< "\n\t\t\t\t\t--------------------------------------------" <<endl;
    Sleep(1000);
    string top = "\n\tTOPIC : MORSE CODE CONVERTER USING BINARY TREE AND LINKED LISTS ";
    for (int i = 0; i<top.length(); i++)
        {
            Sleep(100);
    cout<< top[i];
    }
    cout<< "\n\t-------------------------------\n"<<endl;
    string crt = "\tSUBMITTED BY : ";
    for (int i = 0; i<crt.length(); i++)
        {
            Sleep(100);
    cout<<crt[i];
    }
    cout<< "\n\t------------------------- \n"<<endl;
    string name_s = "\t1. Ankita Jha - 9922103166\n\t2. Khushi Singh - 9922103148\n\t3. Shivam Pandey - 9922103165\n\t4. Pragya Sharma - 9922103161\n ";
    for (int i = 0; i<name_s.length(); i++)
        {
            Sleep(100);
    cout<<name_s[i];
    }
    Sleep(1000);
    system("pause");
    system("cls");
    }


    void print()
    {
        Node *p = head;
        while (p != NULL)
            {
                cout << p->data;
        p = p->next;
        }
    }
/*  */

        int main()
        {
            intro();
            int n;
            string st;
            label:system("color 0a");
            cout<<endl<<endl<<endl<<endl<<"What do you want ?"<<endl<<"1. Morse Code to Alphabet"<<endl<<"2. Alphabet to Morse Code"<<endl<<"3. Caesar Cipher"<<endl<<"4. Know more about Ciphers"<<endl<<"5. Exit"<<endl;
            cin>>n;
            getline(cin,st);

            if(n==1)
                {
                    system("color 0b");
            struct node *head = createNode(2);
            struct node *A = createNode('A');
            struct node *B = createNode('B');
            struct node *C = createNode('C');
            struct node *D = createNode('D');
            struct node *E = createNode('E');
            struct node *F = createNode('F');
            struct node *G = createNode('G');
            struct node *H = createNode('H');
            struct node *I = createNode('I');
            struct node *J = createNode('J');
            struct node *K = createNode('K');
            struct node *L = createNode('L');
            struct node *M = createNode('M');
            struct node *N = createNode('N');
            struct node *O = createNode('O');
            struct node *P = createNode('P');
            struct node *Q = createNode('Q');
            struct node *R = createNode('R');
            struct node *S = createNode('S');
            struct node *T = createNode('T');
            struct node *U = createNode('U');
            struct node *V = createNode('V');
            struct node *W = createNode('W');
            struct node *X = createNode('X');
            struct node *Y = createNode('Y');
            struct node *Z = createNode('Z');
            head->left = E;
            head->right = T;
            E->left = I;
            E->right = A;
            T->right = M;
            T->left=N;
            I->left = S;
            I->right = U;
            A->left = R;
            A->right = W;
            N->left = D;
            N->right = K;
            M->left = G;
            M->right = O;
            S->left = H;
            S->right = V;
            U->left = F;
            U->right = NULL;
            R->left = L;
            R->right = NULL;
            W->left = P;
            W->right = J;
            D->left = B;
            D->right = X;
            K->left = C;
            K->right = Y;
            G->left = Z;
            G->right = Q;
            O->left = NULL;
            O->right = NULL;
            cout<<"Enter the morse code: "<<endl;
            string str;
getline(cin,str);
int n = (str.length());
cout<<"Converted Text: ";
traversal(str, n, head);
cout<<endl<<endl;
system("pause");
system("cls");
goto label;
}

if(n==2)
{
system("color 0f");
string morseCode[36];
morseCode[0] = ".- ";
morseCode[1] = "-... ";
morseCode[2] = "-.-. ";
morseCode[3] = "-.. ";
morseCode[4] = ". ";
morseCode[5] = "..-. ";
morseCode[6] = "--. ";
morseCode[7] = ".... ";
morseCode[8] = ".. ";
morseCode[9] = ".--- ";
morseCode[10] = "-.- ";
morseCode[11] = ".-.. ";
morseCode[12] = "-- ";
morseCode[13] = "-. ";
morseCode[14] = "--- ";
morseCode[15] = ".--. ";
morseCode[16] = "--.- ";
morseCode[17] = ".-. ";
morseCode[18] = "... ";
morseCode[19] = "- ";
morseCode[20] = "..- ";
morseCode[21] = "...- ";
morseCode[22] = ".-- ";
morseCode[23] = "-..- ";
morseCode[24] = "-.-- ";
morseCode[25] = "--.. ";
morseCode[26] = "----- ";
morseCode[27] = ".---- ";
morseCode[28] = "..--- ";
morseCode[29] = "...-- ";
morseCode[30] = "....- ";
morseCode[31] = "..... ";
morseCode[32] = "-.... ";
morseCode[33] = "--... ";
morseCode[34] = "---.. ";
morseCode[35] = "----. ";
string userInput;
cout << "Input a message to translate into Morse code:" << endl;
getline(cin, userInput);
for (int i = 0; i < userInput.length(); i++)
{
    int c = userInput[i] - 97;
    if (c >= 0 && c <= 25)
{
    for (int i = 0; i < (morseCode[c]).length(); i++)
    {
        addnode((morseCode[c])[i]);
    }
}
int d = userInput[i] - 65;
if (d >= 0 && d <= 25)
{
for (int i = 0; i < (morseCode[d]).length(); i++)
{
addnode((morseCode[d])[i]);
}
}
int e = userInput[i] - 22;
if (e >= 26 && e <= 35)
{
for (int i = 0; i < (morseCode[e]).length(); i++)
{
addnode((morseCode[e])[i]);
}
}
}
print();
cout<<endl<<endl;
system("pause");
system("cls");
goto label;
}

if(n==3)
{
system("color 0d");
cout<<"Enter the message:";
char msg[100];
cin.getline(msg,100);
int i, j, length,choice,key;
cout << "Enter key: ";
cin >> key;
length = strlen(msg);
cout<<"Enter your choice 1. Encryption 2. Decryption ";
cin>>choice;

if (choice==1) 
{
char ch;
for(int i = 0; msg[i] != '\0'; ++i)
{
char ch = msg[i];
if (ch >= 'a' && ch <= 'z'){
ch = ch + key;
if (ch > 'z') 
{
ch = ch - 'z' + 'a' - 1;
}
msg[i] = ch;
}
else if (ch >= 'A' && ch <= 'Z')
{
ch = ch + key;
if (ch > 'Z')
{
ch = ch - 'Z' + 'A' - 1;
}
msg[i] = ch;
}
}
cout<<"Encrypted message: "<<msg;
}
else if (choice == 2)
 {
char ch;
for(int i = 0; msg[i] != '\0'; ++i) 
{
ch = msg[i];
if(ch >= 'a' && ch <= 'z') {
ch = ch - key;
if(ch < 'a'){
ch = ch + 'z' - 'a' + 1;
}
msg[i] = ch;
}
else if(ch >= 'A' && ch <= 'Z') {
ch = ch - key;
if(ch < 'A') {
ch = ch + 'Z' - 'A' + 1;
}
msg[i] = ch;
}
}
cout << "Decrypted message: " << msg;
}
cout<<endl<<endl;
system("pause");
system("cls");
goto label;
}

if(n==4)
{
system("color 0e");
cout<<endl<<endl<<endl<<endl<<"CAESAR CIPHER"<<endl<<endl<<"In cryptography, a Caesar cipher, also known as Caesar's cipher, the shift cipher, Caesar's code, or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. For example, with a left shift of 3, D would be replaced by A, E would become B, and so on. The method is named after Julius Caesar, who used it in his private correspondence."<<endl<<endl<<"Thus to cipher a given text we need an integer value, known as a shift which indicates the number of positions each letter of the text has been moved down. ";
cout<<endl<<endl<<endl<<endl<<"MORSE CODE"<<endl<<endl<<"Morse code is a method used in telecommunication to encode text characters as standardized sequences of two different signal durations, called dots and dashes, or dits and dahs.[3][4] Morse code is named after Samuel Morse, one of the early developers of the system adopted for electrical telegraphy."<<endl<<"The algorithm is very simple. Every character in the English language is substituted by a series of dots and dashes or sometimes just singular dot or dash and vice versa. "<<endl<<endl<<"Every text string is converted into the series of dots and dashes. For this every character is converted into its Morse code and appended in encoded message.";
cout<<endl<<endl;
cout<<endl<<endl;
system("pause");
system("cls");
goto label;
}

if(n==5)
{
system("color 0c");
cout<<endl<<endl<<endl<<endl<<endl<<" Okay ";
return 0;
}
else
{
system("color 4b");
cout<<endl<<endl<<endl<<endl<<endl<<" Try Again"<<endl;
return 0;}}