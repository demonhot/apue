/*
 * =====================================================================================
 *
 *       Filename:  open_memstream.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月05日 17时23分39秒
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
   FILE *out, *in;
   int v, s;
   size_t size;
   char *ptr;

   if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
   }

   in = fmemopen(argv[1], strlen(argv[1]), "r");
   if (in == NULL)
	   err_sys("fmemopen");

   out = open_memstream(&ptr, &size);
   if (out == NULL)
	   err_sys("open_memstream");

   for (;;) {
	   s = fscanf(in, "%d", &v);
	   if (s <= 0)
		   break;

	   s = fprintf(out, "%d ", v * v);
	   if (s == -1)
		   err_sys("fprintf");
   }
   fclose(in);
   printf("before fclose size=%ld; ptr=%s\n", (long) size, ptr);
   fclose(out);
   printf("after fclose size=%ld; ptr=%s\n", (long) size, ptr);
   free(ptr);
   exit(EXIT_SUCCESS);
}

