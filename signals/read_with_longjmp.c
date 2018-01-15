/*
 * =====================================================================================
 *
 *       Filename:  read_with_longjmp.c
 *
 *    Description:  read with longjmp
 *
 *        Version:  1.0
 *        Created:  2018年01月12日 10时12分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <setjmp.h>

static void sig_alarm(int signo);
static jmp_buf jmp_env;

int main(void)
{
	int n;
	char line[MAXLINE];
	if(signal(SIGALRM, sig_alarm) == SIG_ERR)
		err_sys("signal (SIG_ALRM) error");
	if(setjmp(jmp_env) != 0)
		err_quit("read timeout");

	alarm(3);
	if((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
		err_sys("read error");
	
	alarm(0);
	write(STDOUT_FILENO, line, MAXLINE);
	exit(0);

}
void sig_alarm(int signo)
{
	longjmp(jmp_env, 1);
}

