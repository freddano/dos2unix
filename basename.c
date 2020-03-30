/*	$Header: /home/freo/src/Linux/dos2unix/RCS/basename.c,v 1.2 2018/12/26 15:23:44 freo Exp $
*	Fredrik Olofsson	$Date: 2018/12/26 15:23:44 $
*
*	< Description Here >
*	
*	$Log: basename.c,v $
*	Revision 1.2  2018/12/26 15:23:44  freo
*	Added <string.h> to includes.
*
*	Revision 1.1  2018/12/26 15:19:13  freo
*	Initial revision
*
*/
static const char rcsid[] = "$Id: basename.c,v 1.2 2018/12/26 15:23:44 freo Exp $";

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "dos_cvrt.h"

char *
Basename(const char *path) {
    
    char *base_name = 0;
    /*
    Determine the basename of the command invoked. This is necessary since the command 
    could be invoked with a pathname. 
    */
    
    if ( ( base_name = strrchr(path,'/') ) !=0 )
        ++base_name;
    else
        base_name = (char *) path; /* No '/' aka dir-component */
    return base_name;
}

/*	End $Source: /home/freo/src/Linux/dos2unix/RCS/basename.c,v $	*/
