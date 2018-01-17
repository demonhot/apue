/*
 * =====================================================================================
 *
 *       Filename:  mmap_1.c
 *
 *    Description:  mmap
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 10时45分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <sys/mman.h>
#include <fcntl.h>

#define COPYSZ 1024*1024

int main(int argc, char *argv[])
{
	int fdsrc,fddst;
	void *src,*dst;
	int copysz;
	struct stat sbuf;
	off_t offsize = 0;
	if(argc != 3)
		err_sys("usage:%s <source file> <dest file>", argv[0]);
	if((fdsrc = open(argv[1], O_RDONLY)) < 0)
		err_sys("open %s error", argv[1]);
	if((fddst = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, FILE_MODE)) < 0)
		err_sys("open %s error", argv[2]);
	
	if(fstat(fdsrc, &sbuf) < 0)
		err_sys("fstat %s error", argv[1]);

	if(ftruncate(fddst, sbuf.st_size) < 0)
		err_sys("ftruncate error");

	while(offsize < sbuf.st_size) {
		if((sbuf.st_size - offsize) > COPYSZ)
			copysz = COPYSZ;
		else
			copysz = sbuf.st_blksize - offsize;

		if((src = mmap(0, copysz, PROT_READ, MAP_SHARED, fdsrc, offsize)) == MAP_FAILED)
			err_sys("mmap src fail");
		if((dst = mmap(0, copysz, PROT_WRITE | PROT_READ, MAP_SHARED, fddst, offsize)) == MAP_FAILED)
			err_sys("mmap dst fail");
		
		memcpy(dst, src, copysz);
		if((munmap(src, copysz)) < 0)
			err_sys("munmap src error");

		if((munmap(dst, copysz)) < 0)
			err_sys("munmap sr error");
		offsize += copysz;

	}
	exit(0);
}

