ROOT=..
include $(ROOT)/Make.mk

BAR = barrier
EXTRALIBS=-pthread -lrt -lbsd

PROGS = pipe pager popen convert pipe_convert mkfifo message message1 semaphore shared_mem mmap

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
