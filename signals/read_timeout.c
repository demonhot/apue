/*
 * =====================================================================================
 *
 *       Filename:  read_timeout.c
 *
 *    Description:  system call read is interrupted by the signal (here is SIGALRM). 
 *
 *        Version:  1.0
 *        Created:  2018年01月12日 10时00分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
static void sig_alrm(int);
int
main(void)
{
	int n;
	char line[MAXLINE];
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");
	alarm(10);
	if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
		err_sys("read error");
	alarm(0);
	write(STDOUT_FILENO, line, n);
	exit(0);
}
static void
sig_alrm(int signo)
{
/* nothing to do, just return to interrupt the read */
}


