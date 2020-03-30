/*	$Header: /home/freo/src/Linux/dos2unix/RCS/usage.c,v 1.1 2018/12/26 17:33:10 freo Exp $
*	Fredrik Olofsson	$Date: 2018/12/26 17:33:10 $
*
*	Function to display usage and help.
*	
*	$Log: usage.c,v $
*	Revision 1.1  2018/12/26 17:33:10  freo
*	Initial revision
*
*/
static const char rcsid[] = "$Id: usage.c,v 1.1 2018/12/26 17:33:10 freo Exp $";

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dos_cvrt.h"

void usage(const char *cmd) {

    fprintf(stderr, "Usage: %s [ -h | --help ] [--version ] "
        "[-u | --unix ] infile...\n", cmd);
    fputs("\t-h (or --help)\tGives this help display.\n", stderr);
    fputs("\t--version\tDisplays program version.\n\n", stderr);
    fputs("\t-u (or --unix)\tSpecifies UNIX to DOS text\n", stderr);
    fputs("Command unix_cvrt converts UNIX to DOS text, except when -u or --unix is used\n\n", stderr);

}

/*	End $Source: /home/freo/src/Linux/dos2unix/RCS/usage.c,v $	*/
