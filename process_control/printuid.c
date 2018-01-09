/*
 * =====================================================================================
 *
 *       Filename:  printuid.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 19时51分08秒
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
main(void)
{
	printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
	exit(0);
}

