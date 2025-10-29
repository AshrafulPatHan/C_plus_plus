#include <stdio.h>

int main(){
    int a,s;
    s=0;
    a=0;

    // loop
    while(a<=3){
        s=s+a; 
        a = a+1; 
    }
    printf("%d \n",s);
    return 0;
}