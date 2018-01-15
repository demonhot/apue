ROOT=..
include $(ROOT)/Make.mk

PROGS = signal_fun alarm sigcld conflict_signal read_timeout read_with_longjmp signal_set signal_setjmp sigsuspend system

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
