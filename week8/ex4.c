#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rusage temp;
	for(int i = 0;  i < 10; i ++){	
		char*c;
		c = malloc(10000000*sizeof(char));
		memset(c,0, 1e7*sizeof(char));
		getrusage(RUSAGE_SELF, &temp);
		printf("%ld\n",temp.ru_maxrss);
		sleep(1);
	}
	return 0;
}


/*The ru_maxrss is the maximum amount of resident set size (the portion of memory occupied by this process held in RAM */
