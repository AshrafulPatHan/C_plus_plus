#include <stdio.h>

int main(){
    int power,x,y;
    
    scanf("%d %d",&x,&y);

    power = 1;

    for(int i = 0;i < y; i++){
        power = power * x;
    };


    printf("%d to power %d is %d \n",x,y,power);

    return 0;
}

/*
2*1=2
2*2=4
4*2=8
*/