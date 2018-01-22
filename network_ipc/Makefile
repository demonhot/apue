ROOT=..
include $(ROOT)/Make.mk

BAR = barrier
EXTRALIBS=-pthread -lrt -lbsd

PROGS = getaddrinfo gethostent connect_client connect_server 

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
