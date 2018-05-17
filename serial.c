#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double mediaMatrizDiag(double *A, int msize, int nsize);

int main(){

	int n,m,i,j;
	double *A,start,end,t;
	scanf("%d %d",&m,&n);
	A = (double*)malloc(sizeof(double)*(m*n));
	for(i=0; i < m; i++)
		for(j=0; j < n; j++)
			scanf("%lf",&A[i*m+j]);
	
	
	start = omp_get_wtime();
  	t = mediaMatrizDiag(A, m, n);
  	end = omp_get_wtime();

  	printf("TEMPO -> %f\n",end-start);


printf("%.0f\n",t);
for(i=0; i < m; i++){
		for(j=0; j < n; j++)
			printf("%.0lf   ",A[i*m+j]);
		printf("\n");
	}
	return 0;
}

double mediaMatrizDiag(double *A, int msize, int nsize){
	int i,j;
	double maxT= A[0];

    double maxD = A[0];
	int length = msize*nsize;
	for(i=0; i <= length; i++){
		int curLine = i/msize, lastLine = (i-1)/msize;
		if(curLine > lastLine){
			A[lastLine*msize + lastLine] = maxD;
			if(maxT < maxD) maxT = maxD;
			maxD = A[i];
		}
		if(maxD < A[i]) maxD = A[i];
	}
	return maxT;
}
