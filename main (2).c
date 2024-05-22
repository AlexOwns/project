#include "lr.h"
int main(){
    int c;
    scanf("%d", &c);
    switch(c){
    case 1: return lab1();
    case 11: return dop1();
    case 2: return lab2();
    case 22: return dop2();
    case 3: return lab3();
    case 33: return dop3();
    case 4: return lab4();
    case 44: return dop4();
    case 5: return lab5();
    case 55: return dop5();
    case 6: return lab6();
    case 66: return dop6();
    case 7: return lab7();
    }
    return 0;
}