#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdint.h>
#include<sys/stat.h>
#include<string.h>

FILE *fp;
DIR *dr;

int main(){
	dr = opendir(".");
	if(dr == NULL){
		printf("Could not open directory");
		return 0;
	}
	fp = fopen("ex4.txt","w");
	if(fp == NULL){
		printf("Could not open file");
		return 0;
	}
	struct dirent *entry;
	struct dirent *arr_entry[100];
	ino_t inode[100];
	memset(arr_entry,0,100*sizeof(struct dirent*));
	memset(inode,0,100*sizeof(ino_t));
	struct stat buff;
	int i = 0,j = 0;
	while((entry = readdir(dr)) != NULL){
		stat(entry->d_name, &buff);
		if(strcmp(entry->d_name,".") != 0  && strcmp(entry->d_name,"..") != 0 && buff.st_nlink >= 2){
			arr_entry[i] = entry;
			i++;
			if(j == 0){
				inode[j] = entry->d_ino;
				j++;
			}
			for(int k = 0 ; k <j ; k++){
				if(inode[k] == entry->d_ino)
					break;
				else{
					if(k == j - 1){
						inode[j] = entry->d_ino;
						j++;
					}
				}
			}
		}
	}
	for(int k = 0 ; k < j ; k++){
		fprintf(fp,"For i node %ju:\n", (uintmax_t)inode[k]);
		for(int l = 0 ; l < i ; l++){
			if(arr_entry[l]->d_ino == inode[k])
				fprintf(fp,"\t%s\n",arr_entry[l]->d_name);
		}
	}
	closedir(dr);
	fclose(fp);
	return 0;
}
