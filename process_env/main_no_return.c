/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main no return
 *					1.if main function no declare to return an integer, the exit status is undefined
 *					2.However, if the return type of main is an integer,
 *					  and main ‘‘falls off the end’’ (an implicit return), the exit status of the process is 0.
 *					  with compiler condition -std=c99
 *
 *        Version:  1.0
 *        Created:  2018年01月08日 09时56分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main()
{
	printf("hello world\n");
}

