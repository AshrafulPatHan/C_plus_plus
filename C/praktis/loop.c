#include <stdio.h>

int main(){
	int a,max=0,i;
	printf("Please enter ten integer number.");
	for(i=1;i<=10;i++){
		scanf("%d",&a);
		if(a>max){
			max=a;
		}
	}
	printf("Maximum number=%d \n",max);
	return 0;
}

