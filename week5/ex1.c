#include<stdio.h>
#include<pthread.h>

int thread_count = 1;
int NUM_THREAD = 3;

void* thread_func(void* pointer){
	printf("Message from thread %d\n",thread_count);
	thread_count++;
	return NULL;
}
int main(){
	pthread_t thread_id;
	for(int i = 0; i < NUM_THREAD; i++){
		printf("Thread %d is created!\n", thread_count);
		pthread_create(&thread_id,NULL,&thread_func,NULL);
		pthread_join(thread_id,NULL);
	}
	pthread_exit(NULL);
	return 0;
	
}
