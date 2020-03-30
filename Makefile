# $Source: /home/freo/src/Linux/dos2unix/RCS/Makefile,v $
# $Revision: 1.8 $
# $Date: 2018/12/26 21:24:58 $

CC=	cc
STD=	_GNU_SOURCE
OBJS=	dos_cvrt.o unix2dos.o dos2unix.o basename.o usage.o putch.o


.c.o:
	$(CC) -c -Wall $(CFLAGS) -D$(STD) $<
   

all:	dos_cvrt unix_cvrt

dos_cvrt: $(OBJS)
	$(CC) $(OBJS) -o dos_cvrt

unix_cvrt:	dos_cvrt
	rm -f unix_cvrt
	ln -s dos_cvrt unix_cvrt

clean:
	rm -f *.o core *~ *.core
  
clobber: clean
	rm -f dos_cvrt unix_cvrt
   
   
# End Makefile