/*
 * =====================================================================================
 *
 *       Filename:  unlink.c
 *
 *    Description:  unlink function
 *					1.unlink a file, you must have the execute and write permission of directory.
 *					2.only when the link count = 0, the content of file can be deleted.
 *					3.if some process open the file, the content of file can not be deleted.
 *					4.when close the file, first check the count of process having the file;
 *					  then check the link count, if equal to 0, delete it.
 *
 *        Version:  1.0
 *        Created:  2018年01月04日 11时37分48秒
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
	if(open("tmpfile", O_RDWR) < 0)
		err_sys("open tmpfile fail");
	if(unlink("tmpfile") < 0)
		err_sys("unlink tmpfile fail");
	printf("file unlinked\n");

	sleep(15);
	printf("done\n");
	exit(0);
}
