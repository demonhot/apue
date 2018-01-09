/*
 * =====================================================================================
 *
 *       Filename:  exec_1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 17时00分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "apue.h"
int
main(int argc, char *argv[])
{
	int i;
	char **ptr;
	extern char **environ;
	for (i = 0; i < argc; i++)
	/* echo all command-line args */
	printf("argv[%d]: %s\n", i, argv[i]);
	for (ptr = environ; *ptr != 0; ptr++)
		printf("%s\n", *ptr);
	/* and all env strings */
	exit(0);
}
