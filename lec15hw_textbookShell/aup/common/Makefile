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

setblock.o: /Users/cherinoh/aup2ex/c4/setblock.c
	$(CC) $(CFLAGS)  -c -o setblock.o /Users/cherinoh/aup2ex/c4/setblock.c

options.o: /Users/cherinoh/aup2ex/common/options.c
	$(CC) $(CFLAGS)  -c -o options.o /Users/cherinoh/aup2ex/common/options.c

syserr.o: /Users/cherinoh/aup2ex/c1/syserr.c
	$(CC) $(CFLAGS)  -c -o syserr.o /Users/cherinoh/aup2ex/c1/syserr.c

ec.o: /Users/cherinoh/aup2ex/common/ec.c
	$(CC) $(CFLAGS)  -c -o ec.o /Users/cherinoh/aup2ex/common/ec.c

pthreadstub.o: /Users/cherinoh/aup2ex/common/pthreadstub.c
	$(CC) $(CFLAGS)  -c -o pthreadstub.o /Users/cherinoh/aup2ex/common/pthreadstub.c

logf.o: /Users/cherinoh/aup2ex/common/logf.c
	$(CC) $(CFLAGS)  -c -o logf.o /Users/cherinoh/aup2ex/common/logf.c

mkmacrostr.o: /Users/cherinoh/aup2ex/common/mkmacrostr.c
	$(CC) $(CFLAGS)  -c -o mkmacrostr.o /Users/cherinoh/aup2ex/common/mkmacrostr.c

extio.o: /Users/cherinoh/aup2ex/c2/extio.c
	$(CC) $(CFLAGS)  -c -o extio.o /Users/cherinoh/aup2ex/c2/extio.c

getblksize.o: /Users/cherinoh/aup2ex/c2/getblksize.c
	$(CC) $(CFLAGS)  -c -o getblksize.o /Users/cherinoh/aup2ex/c2/getblksize.c

time.o: /Users/cherinoh/aup2ex/c1/time.c
	$(CC) $(CFLAGS)  -c -o time.o /Users/cherinoh/aup2ex/c1/time.c

all:  mms
clean:
	rm  mms *.o
