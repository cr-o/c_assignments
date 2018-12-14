# Do not edit this makefile. It was generated automatically 
# with commands like
#
#     $ AUPSRC=/aup # (for example)
#     $ export AUPSRC
#     $ awk -f $AUPSRC/makebuild.awk $AUPSRC/c1/makebuild.spec >$AUPSRC/c1/Makefile
#
# It is incomplete in the sense that there are no header-file
# dependencies.
#
# Use the shell-procedure makebuild to run awk. Then compile
# with a shell-procedure like this one for Linux:
#
# 	AUPSRC=/aup # (for example)
# 	OS=LINUX
# 	LIBS="-lncurses -lutil"
# 	TLIBS=-pthread
# 	export OS LIBS TLIBS
# 	make $2 -f $AUPSRC/$1/Makefile $3
#

defaulttarget: all
# Following must be defined in the environment before you run make:
#
#	OS = SOLARIS or LINUX or FREEBSD or HPUX
#	LIBS = regular (non-thread) libraries (eg, "-lncurses -lutil")
#	TLIBS = thread libraries (eg, "-llthread -llgcc_r")
#	PTHREADSTUB = stub for thread functions (eg, pthreadstub.o), if needed
#	INCLUDES = additional include directory (eg, "-I/usr/local/include/pthread/linuxthreads")
#	Don't forget:
#		export OS LIBS TLIBS PTHREADSTUB INCLUDES
#	Suggestions:
#		Solaris:
#			OS=SOLARIS
#			LIBS="-lrt -lcurses -lsocket -lnsl"
#			TLIBS="-lpthread"
#
#		FreeBSD:
#			OS=FREEBSD
#			LIBS="-lncurses -lutil"
#			TLIBS="-llthread -llgcc_r"
#			PTHREADSTUB=pthreadstub.o
#			INCLUDES="-I/usr/local/include/pthread/linuxthreads"
#
#		Linux:
#			OS=LINUX
#			LIBS="-lncurses -lutil"
#			TLIBS="-pthread"
#
#		HPUX:
#			OS=HPUX
#			LIBS="-lcurses"
#			TLIBS="-lpthread" (not yet checked out)
# Options below (e.g., -Wimplicit) are for gcc mostly. You will have to modify them for a non-gcc compiler.
CFLAGS = $(INCLUDES) -I$(AUPSRC) -I$(AUPSRC)/include -I$(AUPSRC)/common -I$(AUPSRC)/c6 -Wimplicit -Wstrict-prototypes -Wall -D$(OS) -D_REENTRANT -D_THREAD_SAFE -std=c99 -D$(SUV)
CC = gcc
CCPP = g++
CCLINK = gcc
# Same objects are used all the time, sometimes linking in unnecessary files.
AUPOBJS = syserr.o time.o extio.o getblksize.o setblock.o ec.o logf.o options.o macrostr.o

mms: mkmacrostr.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o mms mkmacrostr.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)
#############################################
# Utility to build macro-string program
#############################################
macrostr.o: $(AUPSRC)/common/macrostr.c $(AUPSRC)/common/macrostr.incl
	$(CC) $(CFLAGS) -c  -o macrostr.o $(AUPSRC)/common/macrostr.c

setblock.o: /Users/cherinoh/aup/c4/setblock.c
	$(CC) $(CFLAGS)  -c -o setblock.o /Users/cherinoh/aup/c4/setblock.c

options.o: /Users/cherinoh/aup/common/options.c
	$(CC) $(CFLAGS)  -c -o options.o /Users/cherinoh/aup/common/options.c

syserr.o: /Users/cherinoh/aup/c1/syserr.c
	$(CC) $(CFLAGS)  -c -o syserr.o /Users/cherinoh/aup/c1/syserr.c

ec.o: /Users/cherinoh/aup/common/ec.c
	$(CC) $(CFLAGS)  -c -o ec.o /Users/cherinoh/aup/common/ec.c

pthreadstub.o: /Users/cherinoh/aup/common/pthreadstub.c
	$(CC) $(CFLAGS)  -c -o pthreadstub.o /Users/cherinoh/aup/common/pthreadstub.c

logf.o: /Users/cherinoh/aup/common/logf.c
	$(CC) $(CFLAGS)  -c -o logf.o /Users/cherinoh/aup/common/logf.c

mkmacrostr.o: /Users/cherinoh/aup/common/mkmacrostr.c
	$(CC) $(CFLAGS)  -c -o mkmacrostr.o /Users/cherinoh/aup/common/mkmacrostr.c

extio.o: /Users/cherinoh/aup/c2/extio.c
	$(CC) $(CFLAGS)  -c -o extio.o /Users/cherinoh/aup/c2/extio.c

getblksize.o: /Users/cherinoh/aup/c2/getblksize.c
	$(CC) $(CFLAGS)  -c -o getblksize.o /Users/cherinoh/aup/c2/getblksize.c

time.o: /Users/cherinoh/aup/c1/time.c
	$(CC) $(CFLAGS)  -c -o time.o /Users/cherinoh/aup/c1/time.c

aupnice: nice.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o aupnice nice.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

fpe: fpe.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o fpe fpe.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

lim: limit.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o lim limit.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sh0: sh0.o builtin.o statuspr.o setenv.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sh0 sh0.o builtin.o statuspr.o setenv.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

t0: t0.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o t0 t0.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

t1: t1.o $(AUPOBJS) 
	$(CCLINK) -o t1 t1.o $(AUPOBJS) $(LIBS) $(TLIBS) 

t2: t2.o $(AUPOBJS) 
	$(CCLINK) -o t2 t2.o $(AUPOBJS) $(LIBS) $(TLIBS) 

t2-mtx: t2-mtx.o $(AUPOBJS) 
	$(CCLINK) -o t2-mtx t2-mtx.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx1: tx1.o $(AUPOBJS) 
	$(CCLINK) -o tx1 tx1.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx2: tx2.o $(AUPOBJS) 
	$(CCLINK) -o tx2 tx2.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx3: tx3.o $(AUPOBJS) 
	$(CCLINK) -o tx3 tx3.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx4: tx4.o $(AUPOBJS) 
	$(CCLINK) -o tx4 tx4.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx5: tx5.o $(AUPOBJS) 
	$(CCLINK) -o tx5 tx5.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx6: tx6.o $(AUPOBJS) 
	$(CCLINK) -o tx6 tx6.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tx7: tx7.o $(AUPOBJS) 
	$(CCLINK) -o tx7 tx7.o $(AUPOBJS) $(LIBS) $(TLIBS) 

uidgrp: uidgrp.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o uidgrp uidgrp.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

waitid: waitid.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o waitid waitid.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

waitpid: waitpid.o statuspr.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o waitpid waitpid.o statuspr.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

x5: x5.o setenv.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o x5 x5.o setenv.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

x5a: x5a.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o x5a x5a.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

limit.o: /Users/cherinoh/aup/c5/limit.c
	$(CC) $(CFLAGS)  -c -o limit.o /Users/cherinoh/aup/c5/limit.c

tx3.o: /Users/cherinoh/aup/c5/tx3.c
	$(CC) $(CFLAGS)  -c -o tx3.o /Users/cherinoh/aup/c5/tx3.c

waitpid.o: /Users/cherinoh/aup/c5/waitpid.c
	$(CC) $(CFLAGS)  -c -o waitpid.o /Users/cherinoh/aup/c5/waitpid.c

setenv.o: /Users/cherinoh/aup/c5/setenv.c
	$(CC) $(CFLAGS)  -c -o setenv.o /Users/cherinoh/aup/c5/setenv.c

statuspr.o: /Users/cherinoh/aup/c5/statuspr.c
	$(CC) $(CFLAGS)  -c -o statuspr.o /Users/cherinoh/aup/c5/statuspr.c

tx4.o: /Users/cherinoh/aup/c5/tx4.c
	$(CC) $(CFLAGS)  -c -o tx4.o /Users/cherinoh/aup/c5/tx4.c

t0.o: /Users/cherinoh/aup/c5/t0.c
	$(CC) $(CFLAGS)  -c -o t0.o /Users/cherinoh/aup/c5/t0.c

nice.o: /Users/cherinoh/aup/c5/nice.c
	$(CC) $(CFLAGS)  -c -o nice.o /Users/cherinoh/aup/c5/nice.c

tx5.o: /Users/cherinoh/aup/c5/tx5.c
	$(CC) $(CFLAGS)  -c -o tx5.o /Users/cherinoh/aup/c5/tx5.c

waitid.o: /Users/cherinoh/aup/c5/waitid.c
	$(CC) $(CFLAGS)  -c -o waitid.o /Users/cherinoh/aup/c5/waitid.c

uidgrp.o: /Users/cherinoh/aup/c5/uidgrp.c
	$(CC) $(CFLAGS)  -c -o uidgrp.o /Users/cherinoh/aup/c5/uidgrp.c

tx1.o: /Users/cherinoh/aup/c5/tx1.c
	$(CC) $(CFLAGS)  -c -o tx1.o /Users/cherinoh/aup/c5/tx1.c

t1.o: /Users/cherinoh/aup/c5/t1.c
	$(CC) $(CFLAGS)  -c -o t1.o /Users/cherinoh/aup/c5/t1.c

fpe.o: /Users/cherinoh/aup/c5/fpe.c
	$(CC) $(CFLAGS)  -c -o fpe.o /Users/cherinoh/aup/c5/fpe.c

builtin.o: /Users/cherinoh/aup/c5/builtin.c
	$(CC) $(CFLAGS)  -c -o builtin.o /Users/cherinoh/aup/c5/builtin.c

t2-mtx.o: /Users/cherinoh/aup/c5/t2-mtx.c
	$(CC) $(CFLAGS)  -c -o t2-mtx.o /Users/cherinoh/aup/c5/t2-mtx.c

tx6.o: /Users/cherinoh/aup/c5/tx6.c
	$(CC) $(CFLAGS)  -c -o tx6.o /Users/cherinoh/aup/c5/tx6.c

x5.o: /Users/cherinoh/aup/c5/x5.c
	$(CC) $(CFLAGS)  -c -o x5.o /Users/cherinoh/aup/c5/x5.c

tx2.o: /Users/cherinoh/aup/c5/tx2.c
	$(CC) $(CFLAGS)  -c -o tx2.o /Users/cherinoh/aup/c5/tx2.c

t2.o: /Users/cherinoh/aup/c5/t2.c
	$(CC) $(CFLAGS)  -c -o t2.o /Users/cherinoh/aup/c5/t2.c

sh0.o: /Users/cherinoh/aup/c5/sh0.c
	$(CC) $(CFLAGS)  -c -o sh0.o /Users/cherinoh/aup/c5/sh0.c

x5a.o: /Users/cherinoh/aup/c5/x5a.c
	$(CC) $(CFLAGS)  -c -o x5a.o /Users/cherinoh/aup/c5/x5a.c

tx7.o: /Users/cherinoh/aup/c5/tx7.c
	$(CC) $(CFLAGS)  -c -o tx7.o /Users/cherinoh/aup/c5/tx7.c

all:  tx6 uidgrp tx7 lim x5a x5 t2-mtx waitpid sh0 aupnice waitid t0 tx1 t1 fpe tx2 t2 tx3 tx4 tx5
clean:
	rm  tx6 uidgrp tx7 lim x5a x5 t2-mtx waitpid sh0 aupnice waitid t0 tx1 t1 fpe tx2 t2 tx3 tx4 tx5 *.o
