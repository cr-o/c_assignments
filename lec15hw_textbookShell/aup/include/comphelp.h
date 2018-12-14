#ifndef _COMPHELP_H_
#define _COMPHELP_H_

#ifdef __cplusplus
extern "C" {
#endif

#define _BSD_SOURCE

#define _POSIX_C_SOURCE 200809L

#ifdef _POSIX_SOURCE /* tmp */
#error
#endif

/*
	FREEBSD and DARWIN (Mac OS X) have many similarities, and some differences. Use BSD_DERIVED
	to treat them the same, and the separate symbols (FREEBSD or DARWIN) to treat them
	differently.
*/
#if defined(FREEBSD) || defined(DARWIN)
#define BSD_DERIVED	//#define BSD_DERIVED
#endif

#ifndef __EXTENSIONS__
#define UNDEF__EXTENSIONS__
#endif
	

/* Special case for OS X 10.4+; see comment above dated 7-My-2005. */
#if defined(SUV_SUS3) && defined(DARWIN)
#include "suvreq.h"
#endif

/*[defs1]*/
#if !defined(BSD_DERIVED) /* _POSIX_SOURCE too restrictive */
#define SUV_SUS2
#include "suvreq.h"
#endif

#include <sys/types.h>
#include <unistd.h>

#if !defined(__cplusplus) && !defined(SKIP_BOOL)
#include <stdbool.h> /* C99 only */
#endif
/*[]*/
#include <signal.h>

#if defined(SOLARIS) || defined(HPUX)
#ifndef __EXTENSIONS__
#define __EXTENSIONS__ /* sys/stat.h won't compile without this */
#endif
#endif
#include <sys/stat.h>
#if defined(SOLARIS) || defined(HPUX)
#ifdef UNDEF__EXTENSIONS__
#undef __EXTENSIONS__
#endif
#endif

/*[defs2]*/
#include <time.h>
#include <limits.h>
#if defined(SOLARIS)
#define _VA_LIST /* can't define it in stdio.h */
#endif
#include <stdio.h>
#if defined(SOLARIS)
#undef _VA_LIST
#endif
#include <stdarg.h> /* this is the place to define _VA_LIST */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>
#ifndef AUP2_SKIP_WAIT
#include <sys/wait.h>
#endif
#include "ec.h"
/*[]*/
#include "logf.h"
#include "options.h"
#include "macrostr.h"
#include "extio.h"

/*
	File-permission-bit symbols
*/
/*[defs-perm]*/
#define PERM_DIRECTORY	S_IRWXU
#define PERM_FILE		(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
/*[]*/

bool setblock(int fd, bool on); /* also in c4/setblock.h */
#define syserrmsg(buf, buf_max, msg, s_errno)\
  syserrmsgtype(buf, buf_max, msg, s_errno, EC_ERRNO)
char *syserrmsgtype(char *buf, size_t buf_max, const char *msg,
  int s_errno, EC_ERRTYPE type);
char *syserrmsgline(char *buf, size_t buf_max,
  int s_errno, EC_ERRTYPE type);
const char *getdate_strerror(int e);
const char *errsymbol(int errno_arg);
void syserr(const char *msg);
void syserr_print(const char *msg);
void timestart(void);
void timestop(char *msg);

unsigned long getblksize(const char *path); /* c2/getvlksize.c */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif