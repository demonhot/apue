/*
 * =====================================================================================
 *
 *       Filename:  alarm.c
 *
 *    Description: if we call a nonreentrant function from a signal handler, the results are unpredictable.
 *				   the getpenam is a nonreentrant function.
 *
 *        Version:  1.0
 *        Created:  2018年01月11日 15时36分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <pwd.h>
static void
my_alarm(int signo)
{
	struct passwd *rootptr;
	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)
		err_sys("getpwnam(root) error");
	alarm(1);
}
int
main(void)
{
	struct passwd *ptr;
	signal(SIGALRM, my_alarm);
	alarm(1);
	for ( ; ; ) {
		if ((ptr = getpwnam("wanghui")) == NULL)
			err_sys("getpwnam error");
		if (strcmp(ptr->pw_name, "wanghui") != 0)
			printf("return value corrupted!, pw_name = %s\n",
		ptr->pw_name);

	}
}
