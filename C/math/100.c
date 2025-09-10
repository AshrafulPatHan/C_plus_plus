#include <stdio.h>

int main()
{
    for(int i = 0; i < 100; i++ )
    {
        if( i == 4 )
        {
            break;
        }
        printf("the number is %d \n",i);
    }
    return 0;
}