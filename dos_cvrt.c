/* dos_cvrt.c */

static const char rcsid[]= "$Id: dos_cvrt.c,v 1.15 2018/12/26 21:54:11 freo Exp freo $";

/* REVISION HISTORY:
*  $Log: dos_cvrt.c,v $
*  Revision 1.15  2018/12/26 21:54:11  freo
*  Added error handling.
*
*  Revision 1.14  2018/12/26 18:46:28  freo
*  Added longopts
*
*  Revision 1.13  2018/12/26 17:58:06  freo
*  Added command line processing.
*
*  Revision 1.12  2018/12/26 15:21:25  freo
*  Moved *Basename to separate file to make the program more modular.
*
*  Revision 1.11  2018/12/26 15:02:13  freo
*  Made Basename function static.
*
*  Revision 1.10  2018/12/26 14:58:35  freo
*  Moved text conversion functions to separate source modules. Added dos_cvrt.h as include-file, for declarations.
*
*  Revision 1.9  2018/12/26 14:44:48  freo
*  Moved basename check to a separate function. Also made it possible to convert more than one file given on the command line.
*
*  Revision 1.8  2018/12/26 06:26:04  freo
*  Separated dos2unix and unix2dos conversions into separate functions.
*
*  Revision 1.7  2018/12/25 20:49:43  freo
*  Completed conversion functions and tested ok.
*
*  Revision 1.6  2018/12/25 19:02:51  freo
*  Fixed a stupid type
*  typo
*
*  Revision 1.5  2018/12/25 19:00:55  freo
*  Coded basename test
*
*  Revision 1.4  2018/12/08 18:14:03  freo
*  Added Version substitution
*
*  Revision 1.3  2018/12/08 18:12:21  freo
*  Demonstration of RCS Substitutions
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include "dos_cvrt.h"

extern char *optarg; /* Option argument */
extern int optind; /* Option Index */
extern int opterr; /* Error handling flag */


int main(int argc, char **argv){
    char *base_name = 0; /* basename of command */
    int rc = 0; /* Command return code */
    int (*conv)(const char *pathname); /* Conv. func. ptr */
    int x;
    static int cmdopt_u = 0; /* -u True if UNIX -> DOS */
    static int cmdopt_v = 0; /* --version */ 
    int cmdx = 0; /* lopts[] index */
    int optch; 	/* Current option character */
    static char stropts[] = "hu"; /* Supported Options */
    static struct option lopts[] = {
        {"help", 0, 0, 'h' }, /* --help */
        { "version", 0, &cmdopt_v, 1}, /* --version. name, has_arg, flag, val  */ 
        { "unix", 0, &cmdopt_u, 1}, /* --unix. */
        { 0, 0, 0, 0}        
    };    
    base_name = Basename(argv[0]); /* Determine basename of command. */
    /*
    Now that we know the basename of the command, we can do different things, depending on how the program was invoked.
    */
    
    if ( !strcmp(base_name, "unix_cvrt") )
              cmdopt_u = 1; /* Pretend that -u was given. */
    
    /* Process all command line options: */
    
    while ( (optch = getopt_long(argc, argv, stropts, lopts, &cmdx)) != EOF )
        switch ( optch ) {
        case 0:		/*  Processed lopts[cmdx] */
            break;
        case 'h':
            usage(base_name);
            return 0;
        case 'u':
            cmdopt_u = 1;
            break;
        default:	/* Unsupported option */
            fprintf(stderr, "Use %s -h or --help for help.\n",base_name);
            return 1;
        }
    if (cmdopt_v != 0) {
        fprintf(stderr, "Version 1.0\n");
        return 0;
    }
    /*
    * Open the input File. Return error if no input file is given.
    */
    if ( argc - optind < 1 )
    {
        fprintf(stderr, "Missing input file.\n");
        fprintf(stderr, "Use %s -h or --help for help\n", base_name);
        return RC_CMDOPTS;
    }
    
    if ( cmdopt_u != 0 )
        conv = unix2dos;
    else
        conv = dos2unix;
        
        
    /* Perform a text conversion */
    for ( x = optind ; x < argc; ++x)
        if ( (rc = conv(argv[x])) !=0 )
            break;
            
    /* Check that our possibly buffered stdout gets flushed without errors */
    
    fflush(stdout);
    if (ferror(stdout)){
        fprintf(stderr, "%s: writing to standard output.\n",strerror(errno));
        rc = RC_WRITERR;
    }
    return rc;
}
