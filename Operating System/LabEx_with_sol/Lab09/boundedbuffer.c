/*
1. Write a C program using the pthread's semaphore to implement the Bounded
Buffer problem. You must implement pseudo-code for the producer as the
"insertbuffer()" function, which will be executed by a producer thread created
by the main program. However, instead of using a forever loop, implement the
"insertbuffer()" to run only forty rounds. The function shows the producer
thread's work, as is shown in the example output. The pseudo-code for
consumer must be implemented as the “readbuffer()” function where the
consumer thread executes this function, the forever loop needs to be changed
to run only forty rounds. The function shows the consumer thread's work, as is
shown in the example output. The main program initializes all semaphores,
creates producer and consumer threads, waits for all threads to finish, and
destroys all semaphores. The example output of the program is as follows:
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#define BUFFER_SIZE 5
int count = 0;
int buffer[BUFFER_SIZE];
sem_t mutex;
sem_t empty;
sem_t full;
void *insertbuffer(void *param);
void *readbuffer(void *param);
int main() {
    pthread_t consumer;
    pthread_t producer;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    sem_init(&mutex,0,1);
    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    pthread_create(&consumer, &attr, readbuffer, NULL);
    pthread_create(&producer, &attr, insertbuffer, NULL);
    pthread_join(consumer,NULL);
    pthread_join(producer,NULL);
    sem_destroy(&full);
    sem_destroy(&empty);
    sem_destroy(&mutex);
    return 0;
}
void *insertbuffer(void *param) {
	int i = 0;
	int in= 0;
	for(i = 0; i < 40;i++) {
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[in] = i;
		in = (in + 1) % BUFFER_SIZE;
		count++;
		if(count == BUFFER_SIZE) {
			printf("Producer Entered %d Buffer Full\n", i);
		}
		else {
			printf("Producer Entered %d Buffer size = %d\n", i, count);
		}
		sem_post(&mutex);
		sem_post(&full);
	}
}
void *readbuffer(void *param){
	int i =0;
	int out = 0;
	int item;
	for(i = 0; i < 40; i++) {
		sem_wait(&full);
		sem_wait(&mutex);
		item = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		count--;
		if (count == 0) {
			printf("Consumer consumed %d Buffer Empty\n", item);
		}
		else {
			printf("Concumer consumed %d buffer size = %d\n", item, count);
		}
		sem_post(&mutex);
		sem_post(&empty);
	}
}