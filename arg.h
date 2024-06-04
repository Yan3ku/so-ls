/* #include <regex.h> */

enum {
	VERBOSE_SILENT = 0,
	VERBOSE_STACK  = 1 << 0,
	VERBOSE_HASH   = 1 << 1
};

typedef struct {
	regex_t *exclude;
	const char *path;
	size_t maxdepth;
	size_t mindepth;
	int verbose;
	int realpath;
} Arg;

void argparse(int argc, char *argv[], Arg *args);
void argfree(Arg *arg);
