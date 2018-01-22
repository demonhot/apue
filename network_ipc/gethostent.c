/*
 * =====================================================================================
 *
 *       Filename:  gethostent.c
 *
 *    Description:  struct hostent *gethostent(void);
 *
 *        Version:  1.0
 *        Created:  2018年01月19日 11时46分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <netdb.h>
#include <arpa/inet.h>

int main(void)
{
	struct hostent *host;
	char buf[INET_ADDRSTRLEN];
/*  char *list[10];
	int i;*/
	host = malloc(sizeof(struct hostent));
	if(host == NULL)
		err_sys("MALLOC error");
	memset(host, 0, sizeof(struct hostent));
	host = gethostent();
	if(host == NULL)
		err_sys("gethostent error");
	endnetent();
	printf("host name is %s\n", host->h_name);
	printf("host type is %d\n", host->h_addrtype);
/*  list[0] = *(host->h_addr_list);
//	if(list[0] == NULL)
//		err_sys("h_addr_list is NULL");
//	for(i = 0; list[i] != NULL; i++) {
//		printf("addr list is %s\n", list[i]);
//	}*/
	while(*(host->h_addr_list) != NULL){
		if(inet_ntop(AF_INET, *(host->h_addr_list), buf, INET_ADDRSTRLEN) == NULL)
			err_sys("inet_ntop error");
		printf("addr list is %s\n", buf);
		host->h_addr_list++;
	}
	exit(0);
}
