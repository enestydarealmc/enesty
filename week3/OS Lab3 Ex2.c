#include<stdio.h>

void bubble_sort(int* sp, int len){
	for(int i = 0; i < len ; i++){
		for(int j = 0 ; j < len-i-1; j++){
			if(sp[j]>sp[j+1])
			{
				sp[j] = sp[j]^sp[j+1];
				sp[j+1] = sp[j+1]^sp[j];
				sp[j] = sp[j]^sp[j+1];
			}
		}
	}
}
int main(){
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	printf("Before sorting: ");
	for(int i = 0; i<10;i++)
		printf("%d ", arr[i]);
	printf("\n");
	bubble_sort(arr,10);
	printf("After sorting: ");
	for(int i = 0 ; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
