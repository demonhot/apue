/*
 * =====================================================================================
 *
 *       Filename:  sigcld.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月11日 15时52分23秒
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
static void sig_cld(int);
int
main()
{
	pid_t pid;
	if (signal(SIGCLD, sig_cld) == SIG_ERR)
		perror("signal error");
	if ((pid = fork()) < 0) {
		perror("fork error");
	} else if (pid == 0) {
	/* child */
		sleep(2);
		_exit(0);
	}
	pause();
	exit(0);
	/* parent */
}
static void
sig_cld(int signo) /* interrupts pause() */
{
	pid_t pid;
	int status;
	printf("SIGCLD received\n");
	if (signal(SIGCLD, sig_cld) == SIG_ERR) /* reestablish handler */
		perror("signal error");
	if ((pid = wait(&status)) < 0)
		perror("wait error");
/* fetch child status */
	printf("pid = %d\n", pid);
}

