/*	$Header: /home/freo/src/Linux/dos2unix/RCS/dos2unix.c,v 1.2 2018/12/26 21:18:50 freo Exp $
*	Fredrik Olofsson	$Date: 2018/12/26 21:18:50 $
*
*	DOS to UNIX text conversion. Output to stdout.
*	
*	$Log: dos2unix.c,v $
*	Revision 1.2  2018/12/26 21:18:50  freo
*	Added error checking.
*
*	Revision 1.1  2018/12/26 15:00:12  freo
*	Initial revision
*
*/
static const char rcsid[] = "$Id: dos2unix.c,v 1.2 2018/12/26 21:18:50 freo Exp $";

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "dos_cvrt.h"

int dos2unix(const char *pathname) {
    int rc = 0;
    int ch;
    int cr_flag;
    FILE *in = 0;

        if ( !(in = fopen(pathname, "r")) )
        {
            fprintf(stderr, "%s: opening %s for read.\n", strerror(errno),pathname);
            return RC_OPENERR;
        }

        cr_flag = 0;
        while ( (ch = fgetc(in)) != EOF ) 
        {
            if ( cr_flag && ch != '\n' ) 
            {
                /* This CR did not precede LF */
                if ( put_ch('\r') ) {
                    rc = RC_WRITERR; /* Write failed */
                    goto xit;
                }
            }
            
            if ( !(cr_flag = ch == '\r') )
                if ( put_ch(ch) ) {
                    rc = RC_WRITERR;
                    goto xit;
                }
        }
        
        if ( ferror(in) ) {
            fprintf(stderr, "%s: reading %s\n", strerror(errno),pathname);
            rc = RC_READERR;
        }
        xit:
        fclose(in);
        return rc;
}

/*	End $Source: /home/freo/src/Linux/dos2unix/RCS/dos2unix.c,v $	*/
