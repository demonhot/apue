/*
 * =====================================================================================
 *
 *       Filename:  pipe.c
 *
 *    Description:  pipe
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 13时48分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <sys/wait.h>

#define BUFSIZE 1024
int main(void)
{
	int fd[2];
	pid_t pid;
	char *buf[BUFSIZE];
	int n,status;
	if(pipe(fd) < 0)
		err_sys("pipe error");
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid > 0){
		close(fd[0]);
		write(fd[1], "hello wanghui\n", 14);
		if(wait(&status) != pid)
			err_sys("wait error");
		pr_exit(status);
	}else{
		close(fd[1]);
		n = read(fd[0], buf, BUFSIZE);
		write(STDOUT_FILENO, buf, n);
	}

	exit(0);

}
