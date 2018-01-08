/*
 * =====================================================================================
 *
 *       Filename:  setjmp.c
 *
 *    Description:  setjmp & longjmp
 *					1.longjmp return to main, it will roll back automatic and register variables.
 *					2.When we enable optimization, both autoval and regival go into registers, 
 *					  even though the former wasn’t declared register, and the volatile variable stays in memory.
 *					3.Without optimization, all five variables are stored in memory. 
 *
 *        Version:  1.0
 *        Created:  2018年01月08日 16时21分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <setjmp.h>
static void f1(int, int, int, int);
static void f2(void);
static jmp_buf jmpbuffer;
static int globval;
int
main(void)
{
	int autoval;
	register int regival;
	volatile int volaval;
	static int statval;
	globval = 1; autoval = 2; regival = 3; volaval = 4; statval = 5;
	if (setjmp(jmpbuffer) != 0) {
		printf("after longjmp:\n");
		printf("globval = %d, autoval = %d, regival = %d,"
		" volaval = %d, statval = %d\n",
		globval, autoval, regival, volaval, statval);
		exit(0);
	}
/*
* Change variables after setjmp, but before longjmp.
*/
	globval = 95; autoval = 96; regival = 97; volaval = 98;
	statval = 99;
	f1(autoval, regival, volaval, statval); /* never returns */
	exit(0);
}
static void
f1(int i, int j, int k, int l)
{
	printf("in f1():\n");
	printf("globval = %d, autoval = %d, regival = %d,"
	" volaval = %d, statval = %d\n", globval, i, j, k, l);
	f2();
}
static void
f2(void)
{
	longjmp(jmpbuffer, 1);
}


