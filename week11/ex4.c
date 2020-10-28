#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main(void){
	const char *src = "./ex1.txt", *dst = "./ex1.memcpy.txt";
	
	int fd_src = open(src, O_RDWR, (mode_t)0600);
	int fd_dst = open(dst, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);

	if(fd_src == -1 | fd_dst == -1){
		printf("Could not open source or destination files");
		exit(-1);
	}

	struct stat buf;
	if(stat(src, &buf) == -1){
		printf("Could not get source file's information");
		exit(-1);
	}
	
	int size = buf.st_size;
	
	if(lseek(fd_dst,size-1, SEEK_SET) == -1){
		close(fd_src);
		close(fd_dst);
		printf("Could not resize destination file");
		exit(-1);
	}

	if(write(fd_dst, "", 1) == -1){
		close(fd_src);
		close(fd_dst);
		printf("Could not write onto the last byte of destination file");
		exit(-1);
	}

	char *map_src = mmap(0, size, PROT_READ, MAP_SHARED, fd_src, 0);
	char *map_dst = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd_dst, 0);
	if(map_src == MAP_FAILED | map_dst == MAP_FAILED){
		close(fd_src);
		close(fd_dst);
		printf("Could not map source or destination files");
		exit(-1);
	}

	for(int i = 0 ; i < size ; i++)
		map_dst[i] = map_src[i];

	if(msync(map_dst, size, MS_SYNC) == -1){
		printf("Could not sync destination file to disk");
	}

	if(munmap(map_src, size) == -1 | munmap(map_dst, size) == -1){
		close(fd_src);
		close(fd_dst);
		printf("Coult not unmap source or destination files");
		exit(-1);
	}

	close(fd_src);
	close(fd_dst);
	return 0;
}



