#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	int fd_random = open("/dev/random", O_RDONLY);
	int fd = open("./ex1.txt",O_WRONLY|O_CREAT,(mode_t)0600);
	if(fd < 0 || fd_random < 0){
		printf("Cannot open file");
		close(fd);
		close(fd_random);
		exit(-1);
	}
	
	size_t len = 20;
	char str[len];
	int byte_read=0;
	while(byte_read<len){
		int byte_read_temp = read(fd_random, str + byte_read, len - byte_read);
		if(byte_read_temp < 0){
			printf("Something went wrong while reading");
			close(fd);
			close(fd_random);
			exit(-1);
		}
		byte_read += byte_read_temp;
	}
	
	if(write(fd,str,len) < 0){
		printf("Something went wrong while writing back");
		close(fd);
		close(fd_random);
		exit(-1);
	}

	close(fd);
	close(fd_random);
	return 0;
}
