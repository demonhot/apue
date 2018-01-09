ROOT=..
include $(ROOT)/Make.mk

PROGS = fork vfork wait waitpid race_condition exec exec_1 system tsys printuid nice 

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
