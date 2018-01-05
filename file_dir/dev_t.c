/*
 * =====================================================================================
 *
 *       Filename:  dev_t.c
 *
 *    Description:  dev_t st_dev;
 *					dev_t st_rdev;
 *					1.only charcter and block files have st_rdev.
 *					2.every filename on the system has st_dev, is the device number of
 *					  the file system.
 *
 *
 *        Version:  1.0
 *        Created:  2018年01月04日 15时49分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif
int
main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	for (i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		if (stat(argv[i], &buf) < 0) {
			err_ret("stat error");
			continue;
		}
		printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));

		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
			printf(" (%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "character" : "block", major(buf.st_rdev), minor(buf.st_rdev));
		}
		printf("\n");
	}
	exit(0);
}

