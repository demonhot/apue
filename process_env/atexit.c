/*
 * =====================================================================================
 *
 *       Filename:  atexit.c
 *
 *    Description:  atexit
 *					1.the function is to be called at normal process termination.
 *					2.funtions is called in reverse order of their registration.
 *
 *        Version:  1.0
 *        Created:  2018年01月08日 10时19分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
static void my_exit1(void);
static void my_exit2(void);
static void my_exit3(void);
int
main(void)
{
	if (atexit(my_exit3) != 0)
		err_sys("can’t register my_exit3");
	if (atexit(my_exit2) != 0)
		err_sys("can’t register my_exit2");
	if (atexit(my_exit1) != 0)
		err_sys("can’t register my_exit1");
	if (atexit(my_exit1) != 0)
		err_sys("can’t register my_exit1");
	printf("main is done\n");
	return(0);
}
static void
my_exit1(void)
{
	printf("first exit handler\n");
}
static void
my_exit2(void)
{
	printf("second exit handler\n");
}
static void
my_exit3(void)
{
	printf("third exit handler\n");
}
