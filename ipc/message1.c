/*
 * =====================================================================================
 *
 *       Filename:  message.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 19时05分04秒
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
#include <string.h>
#include <fcntl.h>
#include <sys/msg.h>


struct mymesg{
	long mbyte;
	char mtext[512];
};

int main(int argc, char *argv[])
{
	key_t key;
	int msgqid;
	struct mymesg whmsg;

	if(argc != 2)
		err_sys("usage: %s <filename>",argv[0]);

	key = ftok(argv[1], 1);
	if(key < 0)
		err_sys("ftok error");
	msgqid = msgget(key, S_IRUSR | S_IWUSR);
	if(msgqid < 0)
		err_sys("msgget error");

	memset(&whmsg, 0, sizeof(struct mymesg));

	if(msgrcv(msgqid, &whmsg, 512, 0, IPC_NOWAIT) < 0)
		err_sys("msgrcv error");
	
	printf("remove message ok\n");
	printf("message length:%ld\n", whmsg.mbyte);
	printf("message mtext:%s\n", whmsg.mtext);

	msgctl(msgqid, IPC_RMID, NULL);

	exit(0);
}

