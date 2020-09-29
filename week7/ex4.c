#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void *realloc_custom(void *ptr, unsigned int old_size,unsigned int new_size){
	if(ptr == NULL) return ptr = malloc(new_size);
	if(new_size == 0){
		free(ptr);
	}
	else{
		if(old_size < new_size){
			void *temp = malloc(new_size);		
			memcpy(temp,ptr,old_size);
			ptr = temp;
		}
		else if(old_size > new_size){
			void *temp = malloc(new_size);
			memcpy(temp,ptr,new_size);
			ptr = temp;
		}
	}
	return ptr;
}

int main(){
        //Allows you to generate random number
        srand(time(NULL));

        // Allows user to specify the original array size, stored in variable n1.
        printf("Enter original array size:");
        int n1=0;
        scanf("%d",&n1);

        //Create a new array of n1 ints
        int* a1 = calloc(n1,sizeof(int));
        int i;
        for(i=0; i<n1; i++){
                //Set each value in a1 to 100
                a1[i]=100;

                //Print each element out (to make sure things look right)
                printf("%d ",a1[i]);
        }

        //User specifies the new array size, stored in variable n2.
        printf("\nEnter new array size: ");
        int n2=0;
        scanf("%d",&n2);

        //Dynamically change the array to size n2
        a1 = realloc_custom(a1,n1*sizeof(int),n2*sizeof(int));

        //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

        for(i=0; i<n2;i++){
                //Print each element out (to make sure things look right)
                printf("%d ",a1[i]);
        }

        printf("\n");

        //Done with array now, done with program :D
}

