ROOT=..
include $(ROOT)/Make.mk

BAR = barrier
EXTRALIBS=-pthread -lrt -lbsd

PROGS =threadid thread_join badexit2 cleanup timedlock barrier pthread_read pthread_print 

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
