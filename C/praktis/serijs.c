#include <stdio.h>

// 2+4+6+8

int main(){
    int a,s;
    s=0;
    a=2;

    // loop
    while(a<=6){
        s=s+a;
        a = a+2; 
    }
    printf("%d \n",s);
    return 0;
}