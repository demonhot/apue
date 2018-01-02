/*
 * =====================================================================================
 *
 *       Filename:  mktime.c
 *
 *    Description:  convert time to secs
 *
 *        Version:  1.0
 *        Created:  2018年01月02日 19时01分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"

int main(int argc, char *argv[])
{
	unsigned int year = (unsigned int) atoi(argv[1]);
	unsigned int mon = (unsigned int) atoi(argv[2]);
	unsigned int day = (unsigned int) atoi(argv[3]);
	unsigned int hour = 0;
	unsigned int min = 0;
	unsigned int sec = 0;
	unsigned long result;
	if (0 >= (int) (mon -= 2)) {
		mon += 12;	/* Puts Feb last since it has leap day */
		year -= 1;
	}
	result =((((unsigned long)
		  (year/4 - year/100 + year/400 + 367*mon/12 + day) +
		  year*365 - 719499
	    )*24 + hour /* now have hours */
	  )*60 + min /* now have minutes */
	)*60 + sec; /* finally seconds */
	printf("total sec is %ld\n", result);
	return 0;

}

