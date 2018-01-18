/*
 * =====================================================================================
 *
 *       Filename:  mkfifo.c
 *
 *    Description:  mkfifo
 *
 *        Version:  1.0
 *        Created:  2018年01月17日 17时09分36秒
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


#define PATHNAME    "/home/wanghui/myfifo"

int main (void)
{
    pid_t pid;
    int fd = -1;
    char buf[BUFSIZ] = "";

    if (mkfifo(PATHNAME, 0644) < 0) 
		err_sys("mkfifo error");

    fflush(NULL);
    pid = fork();
    if (pid < 0) {
        perror("fork()");
        exit(1);
    }
    if (!pid) { 
        pid = fork();
        if (pid < 0) {
            perror("fork()");
            exit(1);
        }
        if (!pid) { 
            exit(0);
        }
        
        fd = open(PATHNAME, O_RDWR);
        if (fd < 0) {
            perror("open()");
            exit(1);
        }
        read(fd, buf, BUFSIZ);
        printf("%s", buf);
        write(fd, " World!", 8);
        close(fd);
        exit(0);
    } else { 
        fd = open(PATHNAME, O_RDWR);
        if (fd < 0) 
			err_sys("child 1 open error");
		write(fd, "Hello", 6);
        sleep(2); 
		read(fd, buf, BUFSIZ);
        close(fd);
        puts(buf);
        remove(PATHNAME);
        exit(0);
    }

    return 0;
}

