/*
 * =====================================================================================
 *
 *       Filename:  umask.c
 *
 *    Description:  umask
 *					1.if user creat the file and not umask it before, then system use
 *					the default umask.
 *					2.the umask in the process does not influence the umask outside
 *
 *
 *        Version:  1.0
 *        Created:  2018年01月03日 16时05分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <fcntl.h>
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) 
int main(int argc, char *argv[])
{
	umask(0);
	if(creat("foo", RWRWRW) < 0)
		err_ret("creat foo file fail");

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if(creat("bar", RWRWRW) < 0)
		err_ret("creat bar file fail");

	exit(0);

}

