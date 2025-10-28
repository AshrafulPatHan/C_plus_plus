#include <stdio.h>

int main(){
	int i,sum,n;
	printf("Type the value for n :");
	scanf("%d",&n);
	sum = 0;
	i=1;

	do{
		sum=sum+i;
		i++;
	}while(i <= n);
	printf("\n sum of all numbers from 1 to %d is = %d \n",n,sum);

	return 0;
}

