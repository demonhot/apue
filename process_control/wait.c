/*
 * =====================================================================================
 *
 *       Filename:  wait.c
 *
 *    Description:  wait
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 14时29分52秒
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

int
main(void)
{
	pid_t pid;
	int status;
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)/* child */
		exit(7);
	if (wait(&status) != pid)/* wait for child */
		err_sys("wait error");
	pr_exit(status);/* and print its status */
	if ((pid = fork()) < 0)/* child */
		err_sys("fork error");
	else if (pid == 0)
		abort();/* generates SIGABRT */
	if (wait(&status) != pid)/* wait for child */
		err_sys("wait error");
	pr_exit(status);/* and print its status */
	if ((pid = fork()) < 0)/* child */
		err_sys("fork error");
	else if (pid == 0)
		status /= 0;/* divide by 0 generates SIGFPE */
	if (wait(&status) != pid)/* wait for child */
		err_sys("wait error");
	pr_exit(status);/* and print its status */
	exit(0);
}

