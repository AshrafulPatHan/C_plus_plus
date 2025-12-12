#include <stdio.h>

void myFunction(){
    printf("first function \n");
}

void SumTowNum(int x,int y){
    int sum = x+y;
    printf("%d and %d sum is: %d\n", x, y, sum);
}

int main(){
    myFunction();
    SumTowNum(2,4);
    return 0;
}

