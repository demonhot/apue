/*
 * =====================================================================================
 *
 *       Filename:  race_condition.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 15时48分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
static void charatatime(char *);
int
main(void)
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		charatatime("output from child\n");
	} else {
		charatatime("output from parent\n");
	}
	exit(0);
}
static void
charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	/* set unbuffered */
	for (ptr = str; (c = *ptr++) != 0; )
		putc(c, stdout);
}


