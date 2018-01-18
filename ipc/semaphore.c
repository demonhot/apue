/*
 * =====================================================================================
 *
 *       Filename:  semaphore.c
 *
 *    Description:  P:S=S-1, if S>=0,the process get the resource, otherwise the process wait for it.
 *					V:S=S+1, if S>0,it wakeup the process waiting for the resource.
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 20时51分10秒
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
#include <sys/sem.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/wait.h>

#define PROCNUM 20
#define FILENAME "wh.txt"


void P(int semid)
{
	struct sembuf op;
	op.sem_num = 0;
	op.sem_op = -1;
	op.sem_flg = 0;

	while(semop(semid, &op, 1) < 0) {
		if((errno != EINTR) && (errno != EAGAIN)){
			err_sys("semop error");
		}
	}

}


void V(int semid)
{
	struct sembuf op;
	op.sem_num = 0;
	op.sem_op = 1;
	op.sem_flg = 0;

	while(semop(semid, &op, 1) < 0) {
		if((errno != EINTR) && (errno != EAGAIN)){
			err_sys("semop error");
		}
	}
}

void func_add(int semid)
{
	FILE *fp;
	char buf[BUFSIZ];
	if((fp = fopen(FILENAME, "r+")) == NULL)
		err_sys("fopen file error");
	P(semid);
	if(fgets(buf, BUFSIZ, fp) == NULL)
		err_sys("fgets error");
	rewind(fp);
	fprintf(fp, "%d", atoi(buf) + 1);
	V(semid);
}


int main (void)
{
	int semid;
	int i;
	pid_t pid;
	if((semid = semget(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR)) < 0)
		err_sys("init semaphore error");
	if(semctl(semid, 0, SETVAL, 1) < 0)
		err_sys("set semnum error");
	
	for(i = 0; i < PROCNUM; i++) {
		pid = fork();
		if(pid < 0)
			err_sys("fork error");
		if(pid == 0){
			func_add(semid);
			exit(1);
		}
	}

	for(i = 0; i < PROCNUM; i++) {
		wait(NULL);
	}
	semctl(semid, 0, IPC_RMID);
	exit(0);
}

