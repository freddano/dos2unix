# $Source$
# $Revision$
# $Date$

CC=	cc
STD=	_GNU_SOURCE
OBJS=	file1.o file2.o


.c.o:
	$(CC) -c -Wall $(CFLAGS) -D$(STD) $<
   

all:	target1 target2

target1:	$(OBJS)
	$(CC) $(OBJS) -o target1
	
target2:	target1
	rm -f target2
	ln -s target1 target2

clean:
	rm -f *.o core *~
  
clobber:	clean
	rm -f target1 target2
   
   
# End Makefile