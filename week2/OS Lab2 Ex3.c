#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Error: Invalid number of input, please try again!");
		return 1;
	}
	int i,j,k; 
	i = atoi(argv[1]);
	for (j = 0; j < i; j++){
		for (k =0 ; k <= 2*i-1; k++){
			if(k>=i-j&&k<=i+j)
				printf("*");
			else printf(" ");
			}
		printf("\n");
	}	
}
