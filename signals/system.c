/*
 * =====================================================================================
 *
 *       Filename:  system.c
 *
 *    Description:  system
 *					1.system() executes a command specified in command by calling /bin/sh -c command, 
 *					and returns after the command has been completed.  During execution of the command, 
 *					SIGCHLD will be blocked, and SIGINT and SIGQUIT will be ignored.
 *					2.while exec system("/bin/ed"), first fork /bin/sh, then fork /bin/ed
 *
 *        Version:  1.0
 *        Created:  2018年01月12日 17时27分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"

static void
sig_int(int signo)
{
	printf("caught SIGINT\n");
}
static void
sig_chld(int signo)
{
	printf("caught SIGCHLD\n");
}
int
main(void)
{
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	if (signal(SIGCHLD, sig_chld) == SIG_ERR)
		err_sys("signal(SIGCHLD) error");
	if (system("/bin/ed") < 0)
		err_sys("system() error");
	exit(0);
}


