/*
 * =====================================================================================
 *
 *       Filename:  tsys.c
 *
 *    Description:  ./tsys ./printuid
 *					1.print the real user-id and effective user-id 
 *					2.if chmod u+s tsys, and chown root tsys. the effective user-id is root
 *					3.the superuser permissions that we gave the tsys are retained across fork and exec that are done by system.
 *					  it's a security hole.
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 19时50分22秒
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
main(int argc, char *argv[])
{
	int status;
	if (argc < 2)
		err_quit("command-line argument required");
	if ((status = system(argv[1])) < 0)
		err_sys("system() error");
	pr_exit(status);
	exit(0);
}

