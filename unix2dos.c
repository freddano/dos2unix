/*	$Header: /home/freo/src/Linux/dos2unix/RCS/unix2dos.c,v 1.3 2018/12/26 21:54:54 freo Exp freo $
*	Fredrik Olofsson	$Date: 2018/12/26 21:54:54 $
*
*	Unix to DOS text conversion function.
*	
*	$Log: unix2dos.c,v $
*	Revision 1.3  2018/12/26 21:54:54  freo
*	Added error handling.
*
*	Revision 1.2  2018/12/26 21:11:00  freo
*	Added error checking.
*
*	Revision 1.1  2018/12/26 14:56:11  freo
*	Initial revision
*
*/
static const char rcsid[] = "$Id: unix2dos.c,v 1.3 2018/12/26 21:54:54 freo Exp freo $";

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "dos_cvrt.h"

int unix2dos(const char *pathname) {
    int ch;
    int rc = 0;
    FILE *in = 0;
    
        if ( !(in = fopen(pathname, "r")) )
        {
            fprintf(stderr, "%s: opening %s for read..\n", strerror(errno),pathname);
            return RC_OPENERR;
        }
        /* Perform a UNIX -> DOS conversion */
        /* puts("UNIX to DOS conversion"); */
        while ( (ch=fgetc(in)) != EOF) 
        {
            if ( ch == '\n' )
                if ( put_ch('\r') ) {;
                    rc = RC_WRITERR; /* Write failed */
                    goto xit;
                }
            if ( put_ch(ch) ) {
            rc = RC_WRITERR;
            goto xit;
            }    
        }
        /* Test for a read error: */
        if ( ferror(in) ) {
            fprintf(stderr, "%s reading %s\n", strerror(errno), pathname);
            rc = RC_READERR;
           }
    xit:
    fclose(in);
    return rc;
}


/*	End $Source: /home/freo/src/Linux/dos2unix/RCS/unix2dos.c,v $	*/
