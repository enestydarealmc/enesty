#include<stdio.h>
#include<pthread.h>
long long int timestamp;
int prod_sleep = 0;
int cons_sleep = 1;
char s[10];
int ind = 0;

void *producer(void* pointer){
	while(1){
		if(prod_sleep == 1) continue;
		if(ind == 10)
		{
			prod_sleep = 1;
			cons_sleep = 0;
			printf("Finish producing at timestamp %lld",timestamp);
			continue;
		}
		s[ind] = ind+ '0';
		ind++;
	}
	pthread_exit(NULL);
	return NULL;
}

void *consumer(void* pointer){
	while(1){
		if(cons_sleep == 1) continue;
		if(ind == 0){
			prod_sleep = 0;
			cons_sleep = 1;
			continue;
		}
		printf("%c",s[ind]);
		ind--;
	}
	pthread_exit(NULL);
	return NULL;
}

int main(){
	pthread_t prod,cons;
	pthread_create(&prod,NULL,producer,NULL);
	pthread_create(&cons,NULL,consumer,NULL);
	while(1);
	return 0;
}
