#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define ROWA1 2
#define COLA1 3
#define ROWA2 3
#define COLA2 2
int array1[][3] = {{5,6,7},{4,8,9}};
int array2[][2] = {{6,4},{5,7},{1,1}}; 
int result[ROWA1][COLA2];
void *multiplier(void *param);
int main(int argc, char *argv[]) {
	int i = 0, j=0, r=0; 
	pthread_t tid[ROWA1][COLA2];
	int *rowcol;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for (i =0; i < ROWA1; i++) {
		for (j = 0; j < COLA2; j++) {
			rowcol = (int *) malloc(2 * sizeof(int));
			rowcol[0] = i;
			rowcol[1] =j;
			pthread_create(&tid[i][j], &attr, multiplier, rowcol);
		
		}
	}
	/* now wait for the thread to exit */
	for(i = 0; i < ROWA1; i++) {
		for(j=0; j< COLA2; j++) {
			pthread_join(tid[i][j], NULL);
		}
	}
	for(i = 0; i < ROWA1; i++) {
		for(j=0; j< COLA2; j++) {
			printf("%d ", result[i][j]);	
		}
		printf("\n");
	}
}

/* the thread will begin control in this function */
void *multiplier (void *param) {
	int i,j;
	int *val = param;
	int row = val[0], col=val[1];
	int sum = 0;
	for(i =0; i < ROWA2;i++) {
		sum += array1[row][i] * array2[i][col];
	}
	result[row][col] = sum;
	pthread_exit(0);
}
