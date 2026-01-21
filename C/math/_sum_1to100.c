#include <stdio.h>

int main(){
    int i,sum;

    i = 0;
    sum = 0;

    while(i <= 5){
        sum = sum + i;

        i = i+1;
    }

    printf("sum is %d \n",sum);
    return 0;
}