VERSION = 1.0
THREADS = 4

CPPFLAGS = -D_DEFAULT_SOURCE -DVERSION=\"${VERSION}\"
CFLAGS   = -ansi -pedantic -Wextra -Wall ${CPPFLAGS} -g
LDFLAGS  =

SRC = prog.c arg.c rcdir.c util.c
OBJ = ${SRC:.c=.o}

all: options prog

options:
	@echo dedup build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

prog: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f prog ${OBJ}

.PHONY: all options clean
