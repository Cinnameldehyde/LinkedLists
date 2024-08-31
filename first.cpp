#include <iostream>
using namespace std ;


 int  main()
 {
    for(int i = 4; i < 0; i--){
        cout << i;
    }

    int a = 10;
    int b = 10;
    if(a>b){
        cout << "false";
    }
    else if(a<b){
        cout << "true";
    }
    else{
        cout << "yes";
    }
    return 0;
 }

