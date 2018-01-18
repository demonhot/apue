/*
 * =====================================================================================
 *
 *       Filename:  popen.c
 *
 *    Description:  popen
 *					1.FILE *fp = popen(cmdstring, "r");
 *						fp connect to the standard output of cmdstring
 *					2.FILE *fp = popen(cmdstring, "w");
 *						fp connect to the standard input of cmdstring
 *					3.the shell command ${PAGER:-more} says to use the value of the shell variable
 *					  PAGER if it is defined and non-null; otherwise, use the string more.
 *						
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 15时18分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"

#define PAGER "${PAGER:-more}"
int main(int argc, char *argv[])
{
	FILE *fpin,*fpout;
	char line[MAXLINE];
	if(argc != 2)
		err_sys("usage %s <filename>", argv[0]);
	if((fpin = fopen(argv[1], "r")) == NULL)
		err_sys("fopen %s error", argv[1]);
	if((fpout = popen(PAGER, "w")) == NULL)
		err_sys("popen error");
	
	while(fgets(line, MAXLINE, fpin) != NULL){
		if (fputs(line, fpout) == EOF)
			err_sys("fputs error to pipe");
	}
	if (ferror(fpin))
		err_sys("fgets error");
	if (pclose(fpout) == -1)
		err_sys("pclose error");
	exit(0);


}

