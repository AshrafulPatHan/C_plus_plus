// gcc math.c -o math -lm
#include <stdio.h>
#include <math.h>

int main()
{
    double num,root;
    scanf("%lf",&num);
    root = sqrt(num);
    printf("square root of %lf is %lf\n",num,root); 

    return 0;
}