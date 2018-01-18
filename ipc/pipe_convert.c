/*
 * =====================================================================================
 *
 *       Filename:  pipe_convert.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 15时50分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	FILE *fpin;
	char line[MAXLINE];
	if((fpin = popen("./convert", "r")) == NULL)
		err_sys("popen error");
	for( ; ; ){
		fputs("prompt> ", stdout);
		fflush(stdout);
		if(fgets(line, MAXLINE, fpin) == NULL)
			break;
		if(fputs(line, stdout) == EOF)
			err_sys("fputs error");

	}
	if (pclose(fpin) == -1)
		err_sys("pclose error");
	putchar('\n');
	exit(0);
}

