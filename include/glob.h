/*	$NetBSD: glob.h,v 1.5 1994/10/26 00:55:56 cgd Exp $	*/

/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Guido van Rossum.
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
 *	@(#)glob.h	8.1 (Berkeley) 6/2/93
 */

#ifndef _GLOB_H_
#define	_GLOB_H_

#include <sys/cdefs.h>

struct stat;
typedef struct {
	int gl_pathc;		/* Count of total paths so far. */
	int gl_matchc;		/* Count of paths matching pattern. */
	int gl_offs;		/* Reserved at beginning of gl_pathv. */
	int gl_flags;		/* Copy of flags parameter to glob. */
	__stdargs int (*gl_errfunc) __P((const char *, int));
	char **gl_pathv;	/* List of paths matching pattern. */
				/* Copy of errfunc parameter to glob. */

	/*
	 * Alternate filesystem access methods for glob; replacement
	 * versions of closedir(3), readdir(3), opendir(3), stat(2)
	 * and lstat(2).
	 */
	__stdargs void (*gl_closedir) __P((void *));
	__stdargs struct dirent *(*gl_readdir) __P((void *));
	__stdargs void *(*gl_opendir) __P((const char *));
	__stdargs int (*gl_lstat) __P((const char *, struct stat *));
	__stdargs int (*gl_stat) __P((const char *, struct stat *));
} glob_t;

#define	GLOB_APPEND	0x01	/* append to output from previous call */
#define	GLOB_DOOFFS	0x02	/* use gl_offs */
#define	GLOB_ERR	0x04	/* return on error */
#ifndef _POSIX_SOURCE
#define	GLOB_MAGCHAR	0x08	/* pattern had globbing characters */
#endif
#define	GLOB_MARK	0x10	/* append / to matching directories */
#define	GLOB_NOCHECK	0x20	/* return pattern itself if nothing matches */
#define	GLOB_NOSORT	0x40	/* don't sort */
#ifndef _POSIX_SOURCE
#define	GLOB_QUOTE	0x80	/* quote special chars with \ */
#endif
#define GLOB_NOCASE     0x100   /* case-insensitive sort */
#define GLOB_AMIGA	0x200	/* allow #? as wildcard */

#ifndef _POSIX_SOURCE
#define	GLOB_ALTDIRFUNC	0x0400	/* Use alternately specified directory funcs. */
#define	GLOB_BRACE	0x0800	/* Expand braces ala csh. */
#define	GLOB_NOMAGIC	0x1000	/* GLOB_NOCHECK without magic chars (csh). */
#define	GLOB_TILDE	0x2000	/* Expand tilde names from the passwd file. */
#endif

#define	GLOB_NOSPACE	(-1)	/* Malloc call failed. */
#define	GLOB_ABEND	(-2)	/* Unignored error. */

__BEGIN_DECLS
__stdargs int	glob __P((const char *, int, __stdargs int (*)(const char *, int), glob_t *));
__stdargs void	globfree __P((glob_t *));
__END_DECLS

#endif /* !_GLOB_H_ */
