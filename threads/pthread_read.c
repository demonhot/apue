/*
 * =====================================================================================
 *
 *       Filename:  pthread_read.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月15日 14时53分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <pthread.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 32

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *fun(void *p)
{
	int fd = -1;
    long long n = 0;
    char buf[BUFSIZE] = "";

    fd = open(p, O_RDWR | O_CREAT, 0664);
     /* if err */

    pthread_mutex_lock(&mutex);
 
    read(fd, buf, BUFSIZE);
    lseek(fd, 0, SEEK_SET);
    n = atoll(buf);
    snprintf(buf, BUFSIZE, "%lld\n", ++n);
    write(fd, buf, strlen(buf));
 
    close(fd);
 
    pthread_mutex_unlock(&mutex);
 
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t tid[20];
	int i;
	if(argc != 2) {
		fprintf(stderr, "usage %s <filename>", argv[0]);
		return -1;
	}

	for(i = 0; i < 20; i++) {
		pthread_create(&tid[i], NULL, fun, argv[1]);
	}

	for(i = 0; i < 20; i++) {
		pthread_join(tid[i], NULL);
	}
	
	pthread_mutex_destroy(&tid[i]);

	return 0;
		
}
