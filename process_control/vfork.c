/*
 * =====================================================================================
 *
 *       Filename:  vfork.c
 *
 *    Description:  vfork
 *					1.the child runs in the address space of the parent
					  until it calls either exec or exit
					2._exit does not perform any flushing of standard I/O buffers
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 11时53分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
int globvar = 6;
int
main(void)
{
	int var;
	pid_t pid;
	/* external variable in initialized data */
	/* automatic variable on the stack */
	var = 88;
	printf("before vfork\n");
	if ((pid = vfork()) < 0) {
		err_sys("vfork error");
	} else if (pid == 0) {
		globvar++;
		var++;
		_exit(0);
	}
	/* we don’t flush stdio */
	/* child */
	/* modify parent’s variables */
	/* child terminates */
	/* parent continues here */
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
	exit(0);
}


