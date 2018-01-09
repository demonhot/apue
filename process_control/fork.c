/*
 * =====================================================================================
 *
 *       Filename:  fork.c
 *
 *    Description:  fork
 *					1.fork is called once, and return twice. return value in parent child's PID,
 *					  in child is 0.
 *					2.the parent's data,stack,heap are shared by the parent and child, if either process 
 *					  tries to modify this regions, the kernel only makes a copy of that piece of memory.(COW,copy-on-write)
 *					3.printf redirect to stdout, use line buffer. when buffer is full or meeting new line, flush the buffer;
 *					  otherwise, redirect to file, use full buffer. when buffer is full or call fflush, flush the buffer;
 *
 *
 *
 *        Version:  1.0
 *        Created:  2018年01月08日 17时12分56秒
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
/* external variable in initialized data */
char buf[] = "a write to stdout\n";
int
main(void)
{
	int var;
	pid_t pid;
	/* automatic variable on the stack */
	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		err_sys("write error");
	printf("before fork\n");
	/* we don’t flush stdout */
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {/* child */
		globvar++;  /* modify variables */
		var++;
	} else {
		sleep(2);	/* parent */
	}

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
	var);
	exit(0);
}

