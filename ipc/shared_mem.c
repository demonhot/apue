/*
 * =====================================================================================
 *
 *       Filename:  shared_mem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月18日 10时42分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

#define SHMSIZE	1024
#define SHMMODE S_IRUSR | S_IWUSR

int main(void)
{
	int shmid;
	void *shmptr;
	
	shmid = shmget(IPC_PRIVATE, SHMSIZE, SHMMODE);
	if(shmid < 0)
		err_sys("shmget error");

	if((shmptr = shmat(shmid, 0 , 0)) == (void *)-1)
		err_sys("shmat error");
	
	printf("shared memory from %p to %p\n",(void *)shmptr, (void *)shmptr + SHMSIZE);

	sleep(20);

	if(shmctl(shmid, IPC_RMID, 0) < 0)
		err_sys("shmctl error");

	exit(0);
}
