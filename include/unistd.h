/*	$NetBSD: unistd.h,v 1.25 1995/03/19 22:51:38 mycroft Exp $	*/

/*-
 * Copyright (c) 1991 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)unistd.h	5.13 (Berkeley) 6/17/91
 */

#ifndef _UNISTD_H_
#define	_UNISTD_H_

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/unistd.h>

#define	STDIN_FILENO	0	/* standard input file descriptor */
#define	STDOUT_FILENO	1	/* standard output file descriptor */
#define	STDERR_FILENO	2	/* standard error file descriptor */

#ifndef NULL
#define	NULL		0	/* null pointer constant */
#endif

__BEGIN_DECLS
__stdargs __dead void	 _exit __P((int)) __attribute__((noreturn));
__stdargs int	 access __P((const char *, int));
__stdargs unsigned alarm __P((unsigned));
__stdargs int	 chdir __P((const char *));
__stdargs int	 chown __P((const char *, uid_t, gid_t));
__stdargs int	 close __P((int));
__stdargs size_t	 confstr __P((int, char *, size_t));
__stdargs char	*cuserid __P((char *));
__stdargs int	 dup __P((int));
__stdargs int	 dup2 __P((int, int));
__stdargs int	 execl __P((const char *, const char *, ...));
__stdargs int	 execle __P((const char *, const char *, ...));
__stdargs int	 execlp __P((const char *, const char *, ...));
__stdargs int	 execv __P((const char *, char * const *));
__stdargs int	 execve __P((const char *, char * const *, char * const *));
__stdargs int	 execvp __P((const char *, char * const *));
__stdargs pid_t	 fork __P((void));
__stdargs long	 fpathconf __P((int, int));		/* not yet */
__stdargs char	*getcwd __P((char *, size_t));
__stdargs gid_t	 getegid __P((void));
__stdargs uid_t	 geteuid __P((void));
__stdargs gid_t	 getgid __P((void));
__stdargs int	 getgroups __P((int, int *));
__stdargs char	*getlogin __P((void));
__stdargs pid_t	 getpgrp __P((void));
__stdargs pid_t	 getpid __P((void));
__stdargs pid_t	 getppid __P((void));
__stdargs uid_t	 getuid __P((void));
__stdargs int	 isatty __P((int));
__stdargs int	 link __P((const char *, const char *));
__stdargs off_t	 lseek __P((int, off_t, int));
__stdargs long	 pathconf __P((const char *, int));	/* not yet */
__stdargs int	 pause __P((void));
__stdargs int	 pipe __P((int *));
__stdargs ssize_t	 read __P((int, void *, size_t));
__stdargs int	 rmdir __P((const char *));
__stdargs int	 setgid __P((gid_t));
__stdargs int	 setpgid __P((pid_t, pid_t));
__stdargs pid_t	 setsid __P((void));
__stdargs int	 setuid __P((uid_t));
__stdargs unsigned sleep __P((unsigned));
__stdargs long	 sysconf __P((int));			/* not yet */
__stdargs pid_t	 tcgetpgrp __P((int));
__stdargs int	 tcsetpgrp __P((int, pid_t));
__stdargs char	*ttyname __P((int));
__stdargs int	 unlink __P((const char *));
__stdargs ssize_t	 write __P((int, const void *, size_t));

#ifndef	_POSIX_SOURCE

/* structure timeval required for select() */
#include <sys/time.h>

__stdargs int	 acct __P((const char *));
__stdargs char	*brk __P((const char *));
__stdargs int	 chroot __P((const char *));
__stdargs char	*crypt __P((const char *, const char *));
__stdargs int	 des_cipher __P((const char *, char *, long, int));
__stdargs int	 des_setkey __P((const char *key));
__stdargs int	 encrypt __P((char *, int));
__stdargs void	 endusershell __P((void));
__stdargs int	 exect __P((const char *, char * const *, char * const *));
__stdargs int	 fchdir __P((int));
__stdargs int	 fchown __P((int, uid_t, gid_t));
__stdargs int	 fsync __P((int));
__stdargs int	 ftruncate __P((int, off_t));
__stdargs int	 getdomainname __P((char *, int));
__stdargs int	 getdtablesize __P((void));
__stdargs long	 gethostid __P((void));
__stdargs int	 gethostname __P((char *, int));
__stdargs mode_t	 getmode __P((const void *, mode_t));
__stdargs int	 getpagesize __P((void));
__stdargs char	*getpass __P((const char *));
__stdargs char	*getusershell __P((void));
__stdargs char	*getwd __P((char *));			/* obsoleted by getcwd() */
__stdargs int	 initgroups __P((const char *, int));
__stdargs int	 iruserok __P((u_long, int, const char *, const char *));
__stdargs int	 mknod __P((const char *, mode_t, dev_t));
__stdargs int	 mkstemp __P((char *));
__stdargs char	*mktemp __P((char *));
__stdargs int	 nfssvc __P((int, void *));
__stdargs int	 nice __P((int));
__stdargs void	 psignal __P((unsigned int, const char *));
#ifdef _KERNEL
extern char *sys_siglist[];
#else
extern const char *const sys_siglist[];
#endif
__stdargs int	 profil __P((char *, int, int, int));
__stdargs int	 rcmd __P((char **, int, const char *,
		const char *, const char *, int *));
__stdargs char	*re_comp __P((const char *));
__stdargs int	 re_exec __P((const char *));
__stdargs int	 readlink __P((const char *, char *, int));
__stdargs int	 reboot __P((int));
__stdargs int	 revoke __P((const char *));
__stdargs int	 rresvport __P((int *));
__stdargs int	 ruserok __P((const char *, int, const char *, const char *));
__stdargs char	*sbrk __P((int));
__stdargs int	 select __P((int, fd_set *, fd_set *, fd_set *, struct timeval *));
__stdargs int	 setdomainname __P((const char *, int));
__stdargs int	 setegid __P((gid_t));
__stdargs int	 seteuid __P((uid_t));
__stdargs int	 setgroups __P((int, const int *));
__stdargs void	 sethostid __P((long));
__stdargs int	 sethostname __P((const char *, int));
__stdargs int	 setkey __P((const char *));
__stdargs int	 setlogin __P((const char *));
__stdargs void	*setmode __P((const char *));
__stdargs int	 setpgrp __P((pid_t pid, pid_t pgrp));	/* obsoleted by setpgid() */
__stdargs int	 setregid __P((int, int));
__stdargs int	 setreuid __P((int, int));
__stdargs int	 setrgid __P((gid_t));
__stdargs int	 setruid __P((uid_t));
__stdargs void	 setusershell __P((void));
__stdargs int	 swapon __P((const char *));
__stdargs int	 symlink __P((const char *, const char *));
__stdargs void	 sync __P((void));
__stdargs int	 syscall __P((int, ...));
__stdargs int	 truncate __P((const char *, off_t));
__stdargs int	 ttyslot __P((void));
__stdargs u_int	 ualarm __P((u_int, u_int));
__stdargs int	 undelete __P((const char *));
__stdargs void	 usleep __P((u_int));
__stdargs void	*valloc __P((size_t));			/* obsoleted by malloc() */
__stdargs pid_t	 vfork __P((void));

__stdargs int	 getopt __P((int, char * const *, const char *));
extern	 char *optarg;			/* getopt(3) external variables */
extern	 int opterr;
extern	 int optind;
extern	 int optopt;
extern	 int optreset;
__stdargs int	 getsubopt __P((char **, char * const *, char **));
extern	 char *suboptarg;		/* getsubopt(3) external variable */
#endif /* !_POSIX_SOURCE */
__END_DECLS

#endif /* !_UNISTD_H_ */
