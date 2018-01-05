/*
 * =====================================================================================
 *
 *       Filename:  getcwd.c
 *
 *    Description:  getcwd
 *					return the full path of directory, follow the symbolic link
 *
 *        Version:  1.0
 *        Created:  2018年01月04日 15时31分25秒
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
	char *ptr;
	size_t size;
	if (chdir("/home/wanghui/workspace/apue/apue") < 0)
		err_sys("chdir failed");
	ptr = path_alloc(&size);
	/* our own function */
	if (getcwd(ptr, size) == NULL)
		err_sys("getcwd failed");
	printf("cwd = %s\n", ptr);
	exit(0);
}

