#include <stdio.h>

int main(){
    int a = 15, b = 9;
    int c;

    c = a;
    a = b;
    b = c;

    printf("Value of a , b is %d %d \n", a, b);
    return 0;
}