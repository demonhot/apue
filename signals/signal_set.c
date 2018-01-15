/*
 * =====================================================================================
 *
 *       Filename:  signal_set.c
 *
 *    Description:  use kill -3 pid to send SIGQIUT signal to the process 
 *
 *        Version:  1.0
 *        Created:  2018年01月12日 11时27分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <signal.h>
static void sig_quit(int);
int
main(void)
{
	sigset_t newmask, oldmask, pendmask;
	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_sys("can’t catch SIGQUIT");
	/*
	* Block SIGQUIT and save current signal mask.
	*/
	sigemptyset(&newmask);
	printf("before addset %d\n", (int) *newmask.__val);
	sigaddset(&newmask, SIGQUIT);
	printf("after addset %d\n", (int) *newmask.__val);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");
	printf("after procmask newset: %d, oldmask: %d\n", (int) *newmask.__val, (int) *oldmask.__val);
	sleep(10);
	/* SIGQUIT here will remain pending */
	if (sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	printf("pending mask %d\n", (int) *pendmask.__val);
	if (sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");
	/*
	* Restore signal mask which unblocks SIGQUIT.
	*/
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");
	sleep(10);
	exit(0);
	/* SIGQUIT here will terminate with core file */
}
static void
sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can’t reset SIGQUIT");
}


