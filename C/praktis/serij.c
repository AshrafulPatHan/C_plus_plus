#include <stdio.h>

int main(){
    int a,s;
    s=0;
    a=1;

    // loop
    while(a<=3){
        s=s+a; // 0+1=1 ,1+3=4
        a = a+2; // 1+2=3 ,3+2=5
    }
    printf("%d \n",s);
    return 0;
}