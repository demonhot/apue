/*
 * =====================================================================================
 *
 *       Filename:  waitpid.c
 *
 *    Description:  waitpid
 *					1.If we want to write a process so that it forks a child but we don’t 
 *					want to wait for the child to complete and we don’t want the child to 
 *					become a zombie until we terminate, the trick is to call fork twice
 *
 *        Version:  1.0
 *        Created:  2018年01月09日 14时45分16秒
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
int
main(void)
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
	/* first child */
		if ((pid = fork()) < 0)
			err_sys("fork error");
		else if (pid > 0)
			exit(0);
		/* parent from second fork == first child */
		/*
		* We’re the second child; our parent becomes init as soon
		* as our real parent calls exit() in the statement above.
		* Here’s where we’d continue executing, knowing that when
		* we’re done, init will reap our status.
		*/
		sleep(2);
		printf("second child, parent pid = %ld\n", (long)getppid());
		exit(0);
	}
	if (waitpid(pid, NULL, 0) != pid)
		err_sys("waitpid error");
	/* wait for first child */
	/*
	* We’re the parent (the original process); we continue executing,
	* knowing that we’re not the parent of the second child.
	*/
	exit(0);
}

