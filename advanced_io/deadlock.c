/*
 * =====================================================================================
 *
 *       Filename:  deadlock.c
 *
 *    Description:  #define writew_lock(fd, offset, whence, len) \
 *						lock_reg((fd), F_SETLKW, F_WRLCK, (offset), (whence), (len))
 *					lock_reg define in apue.h
 *					process A lock the file to write, process B can't add write lock to file.But it can write the file directly!
 *
 *        Version:  1.0
 *        Created:  2018年01月16日 14时42分28秒
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

static void
lockabyte(const char *name, int fd, off_t offset)
{
	if (writew_lock(fd, offset, SEEK_SET, 1) < 0)
		err_sys("%s: writew_lock error", name);
	printf("%s: got the lock, byte %lld\n", name, (long long)offset);
}

int
main(void)
{
	int		fd;
	pid_t	pid;

	/*
	 * Create a file and write two bytes to it.
	 */
	if ((fd = creat("templock", FILE_MODE)) < 0)
		err_sys("creat error");
	if (write(fd, "ab", 2) != 2)
		err_sys("write error");

	TELL_WAIT();
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {			/* child */
		lockabyte("child", fd, 0);
		TELL_PARENT(getppid());
		WAIT_PARENT();
		if(lseek(fd, 1, SEEK_SET) < 0)
			err_sys("child lseek error");
		if(write(fd, "d", 1) != 1)
			err_sys("child write bit 1 error");
		lockabyte("child", fd, 1);
	} else {						/* parent */
		lockabyte("parent", fd, 1);
		TELL_CHILD(pid);
		WAIT_CHILD();
		if(lseek(fd, 0, SEEK_SET) < 0)
			err_sys("parent lseek error");
		if(write(fd, "c", 1) != 1)
			err_sys("parent write bit 1 error");

		lockabyte("parent", fd, 0);
	}
	exit(0);
}
