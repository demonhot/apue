/*
 * =====================================================================================
 *
 *       Filename:  chmod.c
 *
 *    Description:  chmod
 *
 *        Version:  1.0
 *        Created:  2018年01月03日 16时46分06秒
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
	struct stat statbuf;
	if(stat("far", &statbuf) < 0)
		err_ret("stat far fail");
	if(chmod("far", (statbuf.st_mode & ~S_IWGRP) | S_ISGID) < 0)
		err_ret("chmod far fail");
	if(chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) < 0)
		err_ret("chmod bar fail");

	exit(0);
}
