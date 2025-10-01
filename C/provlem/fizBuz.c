#include <stdio.h>
void fizzbuzz(int n);

int main(){
    int i;
    
    for (i= 1;i<=100;i++){
        printf("%d: ",i);
        fizzbuzz(i);
    }
    return 0;
}

void fizzbuzz(int n){
    if (n%3 == 0 && n%5 == 0){
        printf("FizzBuzz\n");
    }else if (n%3 == 0){
        printf("Fizz\n");
    }else if (n%5 == 0){
        printf("Buzz\n");
    }else {
        printf("\n");
    }
}