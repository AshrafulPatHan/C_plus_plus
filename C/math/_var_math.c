#include <stdio.h>

int main()
{
    int number1,number2,result;
    number1 = 12;
    number2 = 4;

    result = number1 + number2;
    printf("The number is %d \n",result);
    result = number1 - number2;
    printf("The number is %d \n",result);
    result = number1 * number2;
    printf("The number is %d \n",result);
    result = number1 / number2;
    printf("The number is %d \n",result);

    return 0;
}