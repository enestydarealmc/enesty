#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
	char* str = "Hello";
	int ssize = strlen(str);
	char buff[1024];
	
	setvbuf(stdout, buff, _IOLBF, 1024); //set buffer mode to line buffer
	
	for(int i = 0 ; i < ssize; i++){
		printf("%c",str[i]);
		sleep(1);
	}
	return 0;
}
