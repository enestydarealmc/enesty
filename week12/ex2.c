#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	if(argc < 1){
		printf("Wrong number of arguments");
		exit(-1);
	}
	if(argc == 1){
	
		exit(0);
	}

	int append = 0;
	char opt;
	while((opt = getopt(argc, argv, "a")) != -1){
		if(opt == 'a')
			append = 1;
	}
	
	int filec = argc - optind + 1; //including the stdout file at the end
	FILE* filel[filec];
	filel[filec-1] = stdout;
	for(int i = optind ; i < argc; i++){
		filel[i-optind] = fopen(argv[i], append ? "a" : "w");
		if(filel[i-optind] == NULL){
			printf("Something went wrong while opening files");
			for(int j = 0 ; j <= i-optind ; j++) fclose(filel[j]);
			exit(-1);
		}
	}

	char buf[10];
	int readbyte=0;
	while((readbyte = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
	{
		for(int i = 0 ; i < filec; i++){
			int write_des = fwrite(buf, 1, readbyte, filel[i]);
			if(write_des < 0){
				printf("Something went wrong while writing to files");
				for(int j = 0 ; j < filec - 1; j++) fclose(filel[j]);
				exit(-1);
			}
		}
	}

	for(int i = 0 ; i < filec - 1; i++) fclose(filel[i]);
	return 0;
}
