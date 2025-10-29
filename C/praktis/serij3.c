#include <stdio.h>

int main(){
    int a,s,n;
    s=0;
    n=30;

    // loop
    for(a=3;a<=n;a=a+3){
        s=s+a;
        printf("%d %d \n",s,a);
    }
    printf("%d \n",s);
    return 0;
}