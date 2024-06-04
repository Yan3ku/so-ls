#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <errno.h>
#include "arg.h"
#include "rcdir.h"

int
main(int argc, char *argv[])
{
	Arg arg = {0};
	RCDIR *rcdir = {0};
	char *path;
	int terminate = 0;

	argparse(argc, argv, &arg);
	if((rcdir = rcdiropen(&arg)) == NULL) {
		perror(arg.path);
		terminate = 1;
		errno = 0;
		goto cleanup;
	}
	while((path = rcdirread(rcdir)) != NULL) {
		printf("%s\n", path);
		free(path);
	}
cleanup:
       	if(rcdir) rcdirclose(rcdir);
	argfree(&arg);
	return terminate;
}
