/*
 *	   if write is complete, the offset is incremented by the number of bytes written.
 *	   SEEK_SET
              The offset is set to offset bytes. //the start of the file

       SEEK_CUR
              The offset is set to its current location plus offset bytes.

       SEEK_END
              The offset is set to the size of the file plus offset bytes.
 * */
#include "apue.h"
#include <fcntl.h>
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int
main(void)
{
	int fd;
	if ((fd = creat("file.hole", FILE_MODE)) < 0)
		err_sys("creat error");
	if (write(fd, buf1, 10) != 10)
		err_sys("buf1 write error");
	/*  offset now = 10 */
	if (lseek(fd, 2, SEEK_CUR) == -1)
		err_sys("lseek error");
	/* offset now = 16384 */
	if (write(fd, buf2, 10) != 10)
		err_sys("buf2 write error");
	/* offset now = 16394 */
	exit(0);
	
}
