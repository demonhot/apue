/*
 * =====================================================================================
 *
 *       Filename:  getc_putc.c
 *
 *    Description:  getc & putc
 *
 *        Version:  1.0
 *        Created:  2018年01月05日 11时30分26秒
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
	int c;
	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			err_sys("output error");
	if (ferror(stdin))
		err_sys("input error");
	exit(0);
}
