/*
 * =====================================================================================
 *
 *       Filename:  append.c
 *
 *    Description:  append
 *					1.if multiple preocess open the file, the file must be opened with "O_APPEND"
 *
 *        Version:  1.0
 *        Created:  2018年01月02日 15时44分51秒
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
	int fd;
	char buf[10] = "abcdefg";
	char buf_1[10] = "0";
	fd = open("wh.txt", O_RDWR | O_CREAT | O_APPEND);
	if(fd < 0)
		err_sys("open wh.txt fail");
	if(write(fd, buf, 10) < 0)
		err_sys("write fail");
	lseek(fd, 4, SEEK_SET);
	if(write(fd, buf, 10) < 0)
		err_sys("write fail");
	lseek(fd, -2, SEEK_END);
	printf("read number is %d\n",(int) read(fd, buf_1, 4));
	exit(0);

}

