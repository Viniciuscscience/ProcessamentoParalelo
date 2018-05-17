#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

	int n=8,m=8,i,j;
	
	
	printf("%d %d\n", m, n);

	 for(i=0; i < m; i++){
		for(j=0; j < n; j++)
			printf("%d ",rand()%10000);
		printf("\n");
	} 

	return 0;
}
