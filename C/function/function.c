#include <stdio.h>

void myFunction(){
    printf("first function \n");
}

void SumTowNum(int x,int y){
    int sum = x+y;
    printf("%d and %d sum is: %d\n", x, y, sum);
}

void aboutMe(char name[], int age) {
  printf("Hello %s. You are %d years old.\n", name, age);
}

int main(){
    myFunction(); 
    SumTowNum(2,4); // sum function
    aboutMe("ashraful",18);
    return 0;
}

