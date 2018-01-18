/*
 * =====================================================================================
 *
 *       Filename:  convert.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 15时43分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <ctype.h>
int
main(void)
{
	int c;
	while ((c = getchar()) != EOF) {
	if (isupper(c))
		c = tolower(c);
	if (putchar(c) == EOF)
		err_sys("output error");
	if (c == '\n')
		fflush(stdout);
	}
	exit(0);
}

