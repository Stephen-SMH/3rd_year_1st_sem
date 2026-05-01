#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define clear_buffer() while(getchar() != '\n') 

int num;
int result = 0;
void *runner(void *param);

int main() {
	pthread_t tid;
	pthread_attr_t attr;
	int i, sum = 0;
	
	printf("Please enter number ");
	scanf("%d", &num);
	clear_buffer();
	pthread_attr_init(&attr);
	/* create the thread */
	pthread_create(&tid, &attr, runner, NULL);
	
	for(i = 1; i <= num; i++) {
		sum += i;	
	}
	/* now wait for the thread to exit */
	pthread_join(tid, NULL);
	printf("from parent sum = %d\n", sum);
	result += sum;
	printf("The final result = %d\n", result);
}

/* the thread will begin control in this function */
void *runner (void *val) {
	int i;
	int sum = 0;
	for (i = 1; i <= 2 * num; ++i) {
		sum += i;
	}
	printf("From child sum = %d\n", sum);
	result += sum;
	pthread_exit(0);
}
