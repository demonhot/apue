/*
 * =====================================================================================
 *
 *       Filename:  symlink.c
 *
 *    Description:  symlink
 *
 *        Version:  1.0
 *        Created:  2018年01月02日 14时04分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd,fd1;
	fd = open("./command", O_RDWR);
	if(fd < 0)
		err_sys("can not open command file");
	printf("open command:%d\n", fd);

	if(symlink("./command", "./wh"))
		err_sys("symlink err");
	fd1 = open("./wh", O_RDWR);
	if(fd1 < 0)
		err_sys("can not open wh file");
	printf("open wh:%d\n", fd1);

	printf("command:file descriptor flag is %d\n", fcntl(fd, F_GETFD));
	printf("wh:file descriptor flag is %d\n", fcntl(fd, F_GETFD));

	printf("command:file descriptor flag is %d\n", fcntl(fd, F_GETFL));
	printf("wh:file descriptor flag is %d\n", fcntl(fd, F_GETFL));

	exit(0);
}

