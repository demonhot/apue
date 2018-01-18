/*
 * =====================================================================================
 *
 *       Filename:  message.c
 *
 *    Description:  use ipcrm to delete the message queue in the shell.
 *					1.make the key
 *						ftok
 *					2.create the message queue
 *						msgget,flag with IPC_CREAT | IPC_EXCL
 *					3.send a message
 *						msgsnd,first fill the message struct
 *					4.at last we should delete the meaasge and message queue.
 *						msgrcv----delete the message
 *						msgctl----delete the message queue
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
	if(open(argv[1], O_CREAT | O_RDWR) < 0)
		err_sys("creat %s fail", argv[1]);

	key = ftok(argv[1], 1);
	if(key < 0)
		err_sys("ftok error");
	msgqid = msgget(key, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	if(msgqid < 0)
		err_sys("msgget error");
	memset(&whmsg, 0, sizeof(struct mymesg));
	sprintf(whmsg.mtext, "hello world\n");
	whmsg.mbyte = strlen(whmsg.mtext);
	if(msgsnd(msgqid, &whmsg, whmsg.mbyte, IPC_NOWAIT) < 0)
		err_sys("msgsnd error");
	
	printf("create message ok, msgqid is %d\n", msgqid);

	exit(0);
}

