/*
 * =====================================================================================
 *
 *       Filename:  sigsuspend.c
 *
 *    Description:  sigsuspend
 *					1.temporarily replaces the signal mask of the calling process with the mask given by mask 
 *					  and then suspends the process until delivery of a signal whose action is to invoke a signal
					  handler or to terminate a process.
					2.if signal occure between unblocking signal and pause, then it will be ignored. This function solve
					  the problem.
 *
 *        Version:  1.0
 *        Created:  2018年01月12日 15时49分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
static void sig_int(int);
int
main(void)
{
	sigset_t newmask, oldmask, waitmask;
	pr_mask("program start: ");
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	/*
	* Block SIGINT and save current signal mask.
	*/
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");
	/*
	* Critical region of code.
	*/
	pr_mask("in critical region: ");
	/*
	* Pause, allowing all signals except SIGUSR1.
	*/
	if (sigsuspend(&waitmask) != -1)
		err_sys("sigsuspend error");
	pr_mask("after return from sigsuspend: ");
	/*
	* Reset signal mask which unblocks SIGINT.
	*/
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	/*
	* And continue processing ...
	*/
	pr_mask("program exit: ");
	exit(0);
}

static void
sig_int(int signo)
{
	pr_mask("\nin sig_int: ");
}


