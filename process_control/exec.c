/*
 * =====================================================================================
 *
 *       Filename:  exec.c
 *
 *    Description:  exec
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 16时07分11秒
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
char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL };
int
main(void)
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) { /* specify pathname, specify environment */
		if (execle("/bin/echo", "echoall", "myarg1",
		"MY ARG2", (char *)0, env_init) < 0)
		err_sys("execle error");
	}
	if (waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) { /* specify filename, inherit environment */
	if (execlp("echo", "echo", "only 1 arg", (char *)0) < 0)
		err_sys("execlp error");
	}
	exit(0);
}
