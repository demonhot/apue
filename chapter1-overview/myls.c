#include "apue.h"
#include <dirent.h>

#define pr_err(format, ...)  fprintf(stderr, format, ##__VA_ARGS__)
int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	if (argc != 2) {
		pr_err("correct usage: ls directory_name\n");
		exit(0);
	}
	if ((dp = opendir(argv[1])) == NULL)
		err_sys("can’t open %s", argv[1]);
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);
	closedir(dp);
	exit(0);
}
