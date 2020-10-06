#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
	for(int i = 0;  i < 10; i ++){	
		char*c;
		c = malloc(10000000*sizeof(char));
		memset(c,0,1e7*sizeof(char));
		sleep(1);
	}
	return 0;
}


/*Ex2: Because I did not allocate memory big enough to be out ef physical memory, the swap in (si) and swap out (so) columns did not change
Furthermore, after each second my free space decreases around 10000 kB because my C process eats up the physical memory 10MB at each loop.*/


/*Ex3:    41564  40288   1148 S   0.3   0.6   0:00.01 ex2          
the VIRT is a little bit bigger than RES because there is some part of the process that has been swapped into the secondary memory*/
