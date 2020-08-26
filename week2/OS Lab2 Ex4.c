#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	*a = *a^*b;
	*b = *b^*a;
	*a = *a^*b;
}

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Invalid number of input, please try again!");
		return 1;
	}
	int i = atoi(argv[1]), j = atoi(argv[2]);
	printf("Before:\n");
	printf("First number: %d \nSecond number: %d \n", i,j);
	swap(&i,&j);
	printf("After:\n");
	printf("First number: %d \nSecond number: %d \n", i,j);
}
