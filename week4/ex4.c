#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char cmd[1000];
	printf("Input your command: ");
	scanf("%s",cmd);
	system(strcat(cmd," &"));
	return 0;
}
