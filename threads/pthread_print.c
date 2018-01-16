/*
 * =====================================================================================
 *
 *       Filename:  pthread_print.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年01月15日 15时20分36秒
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

#define TNUM 4
static pthread_mutex_t mutex[TNUM];


static int next(int a)
{
	if( (a + 1) == TNUM)
		return 0;
	return a+1;
}

static void *fun(void *p)
{
	int n = (int)p;
	int ch = n + 'a';
	while(1)
	{
		pthread_mutex_lock(mutex + n);
		write(1, &ch, 1);
		pthread_mutex_unlock(mutex + next(n));
	}
	
	pthread_exit(NULL);
}

int main(void)
{
	int i,err;

	pthread_t tid[4];

	for(i = 0; i < TNUM; i++){
		pthread_mutex_init(mutex+i, NULL);
		pthread_mutex_lock(mutex+i);
		err = pthread_create(&tid[i], NULL, fun, (void *)i);
		if(err < 0)
			printf("create pthread error!\n");
	}
	
	pthread_mutex_unlock(mutex+0);

	alarm(5);

	for(i = 0; i < TNUM; i++){
		pthread_join(tid[i], NULL);
	}
	
	pthread_mutex_destroy(&mutex);

	return 0;
}
