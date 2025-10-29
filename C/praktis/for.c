#include <stdio.h>

int main(){
	int a,s,n;
	scanf("%d",&n);
	s=0;
	for(a=3;a<=n;a+3){
		s=s+a;
	}
	printf("%d",s);

	return 0;
}
