/*
 * =====================================================================================
 *
 *       Filename:  access.c
 *
 *    Description:  validate the file access mode
 *					access use the real user_id and real group_ids of process
 *					if set-user-ID is set,the effective user id is equal to real user id,
 *					no matter who exec the program.(chmod u+s xxx)
 *
 *        Version:  1.0
 *        Created:  2018年01月03日 14时38分19秒
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

int main(int argc, char *argv[])
{
	if(argc != 2)
		err_quit("uasge:access <pathname>");
	if(access(argv[1], R_OK) < 0)
		err_ret("access %s fail", argv[1]);
	else
		printf("access %s OK\n", argv[1]);
	if(open(argv[1], O_RDONLY) < 0)
		err_ret("open %s fail", argv[1]);
	else
		printf("open %s OK\n", argv[1]);

	exit(0);
}
