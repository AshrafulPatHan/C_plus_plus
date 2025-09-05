#include <stdio.h>

int main()
{
    double C,F;
    printf("Enter the celsius template : ");
    scanf("%lf",&C);
    F = ((9/5)* C )+ 32;
    printf("the fahrenheit tempcather %lf\n",F);
    return 0;
}