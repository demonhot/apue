ROOT=..
include $(ROOT)/Make.mk

PROGS = getc_putc io_buffer_type temporary_file mkstemp mem_stream open_memstream

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
