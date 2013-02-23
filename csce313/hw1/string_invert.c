#include <stdio.h>

int main(int argc, char ** argv)
{
	int i, childpid;

	for (i = strlen(argv[1]); i >= 0; i --) {
		if (fork() == 0) {
			printf("%c\n",argv[1][i]);
			break;
		}
	}

	return 0;
}
