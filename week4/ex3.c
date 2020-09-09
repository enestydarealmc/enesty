#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(){
	printf("Input your command: ");
	char cmd[1000];
	gets(cmd);
	for(int i = 0 ; i < strlen(cmd); i++){
		if(cmd[i] == ' ' || cmd[i] == ';')
		{
			cmd[i] = '\0';
			break;
		}
		else if(cmd[i] == '\0')
			break;
	}
	system(cmd);
	return 0;
}
