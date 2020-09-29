#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;
	printf("Input the number of integers N: ");
	scanf("%d",&N);
	int* arr = calloc(N, sizeof(int));
	for(int i = 0 ; i < N; i ++){
		arr[i] = i;
	}
	for(int i = 0 ; i < N; i++)
		printf("%d ",arr[i]);
	free(arr);
}
