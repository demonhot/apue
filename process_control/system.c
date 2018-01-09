/*
 * =====================================================================================
 *
 *       Filename:  system.c
 *
 *    Description:  system
 *					1.sh -c Read commands from the command_string operand instead of from the standard input.
 *		
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 19时37分54秒
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
#include <errno.h>
#include <unistd.h>
int
system(const char *cmdstring)
{
	pid_t pid;
	int status;
	/* version without signal handling */
	if (cmdstring == NULL)
		return(1);
	/* always a command processor with UNIX */
	if ((pid = fork()) < 0) {
		status = -1;
	/* probably out of processes */
	} else if (pid == 0) {
	/* child */
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		_exit(127);
	/* execl error */
	} else {
	/* parent */
		while (waitpid(pid, &status, 0) < 0) {
			if (errno != EINTR) {
				status = -1; /* error other than EINTR from waitpid() */
				break;
			}
		}
	}
	return(status);
}


int
main(void)
{
	int status;
	if ((status = system("date")) < 0)
		err_sys("system() error");
	pr_exit(status);
	if ((status = system("nosuchcommand")) < 0)
		err_sys("system() error");
	pr_exit(status);
	if ((status = system("who; exit 44")) < 0)
		err_sys("system() error");
	pr_exit(status);
	exit(0);
}


