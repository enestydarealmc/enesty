#include<stdio.h>
#include<unistd.h>
int main(void){
	int n = 10;
	pid_t pid = fork();
	for(int i = 0; i < n ; i++){
	if(pid == 0)
		printf("Hello from child [%d - %d]\n",pid,i);
	else if(pid > 0)
		printf("Hello from parent [%d - %d]\n", pid,i);
	else
		return -1;
	}
	return 0;
}
//Out put will be random sequence of hello's from parent and chil, because the CPU randomly excecute them
//there was some change//.
