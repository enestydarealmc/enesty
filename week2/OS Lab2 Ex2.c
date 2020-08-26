#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	char s[100];
	if(argc != 2){
		printf("Error: Invalid number of arguments, try again!");
		return 1;
	}
	printf("Input string: %s\n",argv[1]);
	int i;
	printf("Revered input string: ");
	for(i = strlen(argv[1])-1;i>=0;i--){
		printf("%c",argv[1][i]);
	}
	printf("\n");
	return 0;
}
