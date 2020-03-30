/*	$Header: /home/freo/src/Linux/dos2unix/RCS/putch.c,v 1.1 2018/12/26 21:23:42 freo Exp $
*	Fredrik Olofsson	$Date: 2018/12/26 21:23:42 $
*
*	< Description Here >
*	
*	$Log: putch.c,v $
*	Revision 1.1  2018/12/26 21:23:42  freo
*	Initial revision
*
*/
static const char rcsid[] = "$Id: putch.c,v 1.1 2018/12/26 21:23:42 freo Exp $";

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/*
* Put a character to stdout, with proper error checking.
* Returns: 0 == SUCCESS;
*	  -1 == FAILURE;
*/

int put_ch(int ch) {
    putchar(ch);
    
    if ( ferror(stdout) ) {
        fprintf(stderr, "%s: writing to stdout\n", strerror(errno));
        return -1; /* Write failed */
    }
    return 0;  /* Write succeeded */
}


/*	End $Source: /home/freo/src/Linux/dos2unix/RCS/putch.c,v $	*/
