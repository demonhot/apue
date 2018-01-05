/*
 * =====================================================================================
 *
 *       Filename:  rd_symlink.c
 *
 *    Description:  readlink function
 *					ln -s aaa bbb----bbb direct to aaa
 *					readlink(bbb, &buf, size);---buf="aaa"
 *
 *        Version:  1.0
 *        Created:  2018年01月04日 14时20分30秒
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
main(int argc, char *argv[])
{
   struct stat sb;
   char *linkname;
   ssize_t r;

   if (argc != 2) {
	   fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
	   exit(EXIT_FAILURE);
   }

   if (lstat(argv[1], &sb) == -1) {
	   perror("lstat");
	   exit(EXIT_FAILURE);
   }

   linkname = malloc(sb.st_size + 1);
   if (linkname == NULL) {
	   fprintf(stderr, "insufficient memory\n");
	   exit(EXIT_FAILURE);
   }

   printf("st.size is %d\n", sb.st_size);

   r = readlink(argv[1], linkname, sb.st_size + 1);

   if (r < 0) {
	   perror("lstat");
	   exit(EXIT_FAILURE);
   }
	
   printf("readback number is %d\n", r);
   printf("linkname[6] = %c\n", linkname[6]);
   printf("linkname[7] = %c\n", linkname[7]);
   printf("linkname[8] = %c\n", linkname[8]);

   if (r > sb.st_size) {
	   fprintf(stderr, "symlink increased in size "
					   "between lstat() and readlink()\n");
	   exit(EXIT_FAILURE);
   }

   linkname[sb.st_size] = '\0';

   printf("'%s' points to '%s'\n", argv[1], linkname);

   exit(EXIT_SUCCESS);
}
