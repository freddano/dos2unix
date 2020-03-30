/*	$Header: /home/freo/src/Linux/dos2unix/RCS/dos_cvrt.h,v 1.6 2018/12/26 21:54:27 freo Exp freo $
*	Fredrik Olofsson	$Date: 2018/12/26 21:54:27 $
*
*	< Description Here >
*	
*	$Log: dos_cvrt.h,v $
*	Revision 1.6  2018/12/26 21:54:27  freo
*	Added put_ch definition and some return values.
*
*	Revision 1.5  2018/12/26 17:58:37  freo
*	Added usage declaration.
*
*	Revision 1.4  2018/12/26 15:27:22  freo
*	Changed a stupid typo
*
*	Revision 1.3  2018/12/26 15:25:12  freo
*	Moved last line to silent compiler warning.
*
*	Revision 1.2  2018/12/26 15:20:41  freo
*	Added *Basename declaration.
*
*	Revision 1.1  2018/12/26 14:52:42  freo
*	Initial revision
*
*/
#ifndef _dos_cvrt_h_
#define _dos_cvrt_h_ "@(#)dos_cvrt.h $Revision: 1.6 $"

/* Command exit codes: */

#define RC_CMDOPTS 1
#define RC_OPENERR 2
#define RC_READERR 3
#define RC_WRITERR 4

extern int unix2dos(const char *pathname);
extern int dos2unix(const char *pathname);
extern char *Basename(const char *path);
extern void usage(const char *cmd);
extern int put_ch(int ch);

/*	End $Source: /home/freo/src/Linux/dos2unix/RCS/dos_cvrt.h,v $	*/

#endif /*_dos_cvrt_h_*/