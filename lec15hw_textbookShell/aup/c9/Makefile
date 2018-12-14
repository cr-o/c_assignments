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

alarm_test: alarm_test.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o alarm_test alarm_test.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

ctx: ctx.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o ctx ctx.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

intro: intro.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o intro intro.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

intro2: intro2.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o intro2 intro2.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

jmp: jmp.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o jmp jmp.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

prcssync: prcssync.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o prcssync prcssync.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sighandler: sighandler.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sighandler sighandler.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

siginfo: siginfo.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o siginfo siginfo.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sigmin: sigmin.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o sigmin sigmin.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sigminthr: sigminthr.o $(AUPOBJS) 
	$(CCLINK) -o sigminthr sigminthr.o $(AUPOBJS) $(LIBS) $(TLIBS) 

slp: slp.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o slp slp.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

thrq: thrq.o $(AUPOBJS) 
	$(CCLINK) -o thrq thrq.o $(AUPOBJS) $(LIBS) $(TLIBS) 

tmr: tmr.o $(AUPOBJS) $(PTHREADSTUB)
	$(CCLINK) -o tmr tmr.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

sigmin.o: /Users/cherinoh/aup/c9/sigmin.c
	$(CC) $(CFLAGS)  -c -o sigmin.o /Users/cherinoh/aup/c9/sigmin.c

sigminthr.o: /Users/cherinoh/aup/c9/sigminthr.c
	$(CC) $(CFLAGS)  -c -o sigminthr.o /Users/cherinoh/aup/c9/sigminthr.c

thrq.o: /Users/cherinoh/aup/c9/thrq.c
	$(CC) $(CFLAGS)  -c -o thrq.o /Users/cherinoh/aup/c9/thrq.c

alarm_test.o: /Users/cherinoh/aup/c9/alarm_test.c
	$(CC) $(CFLAGS)  -c -o alarm_test.o /Users/cherinoh/aup/c9/alarm_test.c

slp.o: /Users/cherinoh/aup/c9/slp.c
	$(CC) $(CFLAGS)  -c -o slp.o /Users/cherinoh/aup/c9/slp.c

jmp.o: /Users/cherinoh/aup/c9/jmp.c
	$(CC) $(CFLAGS)  -c -o jmp.o /Users/cherinoh/aup/c9/jmp.c

sighandler.o: /Users/cherinoh/aup/c9/sighandler.c
	$(CC) $(CFLAGS)  -c -o sighandler.o /Users/cherinoh/aup/c9/sighandler.c

intro.o: /Users/cherinoh/aup/c9/intro.c
	$(CC) $(CFLAGS)  -c -o intro.o /Users/cherinoh/aup/c9/intro.c

prcssync.o: /Users/cherinoh/aup/c9/prcssync.c
	$(CC) $(CFLAGS)  -c -o prcssync.o /Users/cherinoh/aup/c9/prcssync.c

siginfo.o: /Users/cherinoh/aup/c9/siginfo.c
	$(CC) $(CFLAGS)  -c -o siginfo.o /Users/cherinoh/aup/c9/siginfo.c

ctx.o: /Users/cherinoh/aup/c9/ctx.c
	$(CC) $(CFLAGS)  -c -o ctx.o /Users/cherinoh/aup/c9/ctx.c

tmr.o: /Users/cherinoh/aup/c9/tmr.c
	$(CC) $(CFLAGS)  -c -o tmr.o /Users/cherinoh/aup/c9/tmr.c

slp-simple.o: /Users/cherinoh/aup/slp-simplec9/slp-simple.c
	$(CC) $(CFLAGS)  -c -o slp-simple.o /Users/cherinoh/aup/slp-simplec9/slp-simple.c

intro2.o: /Users/cherinoh/aup/c9/intro2.c
	$(CC) $(CFLAGS)  -c -o intro2.o /Users/cherinoh/aup/c9/intro2.c

all:  ctx sigmin jmp intro2 siginfo tmr slp sigminthr sighandler intro alarm_test thrq prcssync
clean:
	rm  ctx sigmin jmp intro2 siginfo tmr slp sigminthr sighandler intro alarm_test thrq prcssync *.o
