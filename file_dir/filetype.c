/*
 * =====================================================================================
 *
 *       Filename:  filetype.c
 *
 *    Description:  show the file type
 *					1.when file is symbolic link, lstat	show the infomation of symblic link.
 *					2.when symbolic link, stat show the real file's information.
 *
 *        Version:  1.0
 *        Created:  2018年01月03日 10时51分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	
	
	for(i = 1; i < argc; i++){
		printf("%s----", argv[i]);
		if(lstat(argv[i], &buf) < 0){
			err_ret("lstat error");
			continue;
		}
		if(S_ISREG(buf.st_mode))
			ptr = "regular file";
		else if(S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if(S_ISCHR(buf.st_mode))
			ptr = "character";
		else if(S_ISBLK(buf.st_mode))
			ptr = "block";
		else if(S_ISFIFO(buf.st_mode))
			ptr = "fifo or pipe";
		else if(S_ISLNK(buf.st_mode))
			ptr = "symbolic";
		else if(S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "unkowned file";
		printf("file type:%s\n", ptr);
	}
	exit(0);
		
}
