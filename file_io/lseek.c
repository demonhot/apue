/*
 *	   SEEK_SET
              The offset is set to offset bytes.

       SEEK_CUR
              The offset is set to its current location plus offset bytes.

       SEEK_END
              The offset is set to the size of the file plus offset bytes.
 * */

#include "apue.h"
int
main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");
	exit(0);

}
