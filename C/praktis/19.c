#include <stdio.h>

int main(){
    int roll;
    printf("Type your rool : ");
    scanf("%d",&roll);

    if(roll >= 1 && roll<=30 ){
        printf("A Group");
    }else if(roll > 30 && roll <= 60){
        printf("B Group");
    }else if(roll >60 && roll <=100){
        printf("C Group");
    }else{
        printf("Invalid Roll");
    }

    printf("\n");
    return 0;
}

