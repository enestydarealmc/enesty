#include<sys/types.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char** argv){
	char* str = "This is a nice day";
	int size = strlen(str);
	int fd = open("./ex1.txt", O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
	if(fd == -1){
		printf("Could not open file.");
		exit(-1);
	}
	
	if(lseek(fd,size-1,SEEK_SET) == -1){
		close(fd);
		printf("Could not resize file");
		exit(-1);
	}

	if(write(fd,"", 1) == -1){
		close(fd);
		printf("Could not write at the end of file");
		exit(-1);
	}
	
        char* arr = mmap(0, size-1, PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
        if(arr == MAP_FAILED){                                                                                                          printf("Could not map file into memory");
                printf("Could not map file into memory");
		exit(-1);
        }
	
	for(int i = 0 ; i < size; i++){
		arr[i] = str[i];
	}

	if(msync(arr,size-1, MS_SYNC) == -1){
		printf("Could not sync file to disk");
		exit(-1);
	}

	if(munmap(arr,size-1) == -1){
		close(fd);
		printf("Could not unmap file");
		exit(-1);
	}

	close(fd);
}

