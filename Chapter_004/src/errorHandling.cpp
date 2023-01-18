#include "../headerFiles/headerMain.h"
#include "ename.cpp"


static void terminate (bool aExit_b) {

	char *lString_p8;

	lString_p8 = (char *)getenv("EF_DUMPCORE");

	if (lString_p8 != NULL && *lString_p8 != '\0') {

		abort();
	}

	else if (aExit_b) {

		exit(EXIT_FAILURE);
	}

	else {

        _exit(EXIT_FAILURE);
    }
}

static void outputError( bool useError, int error, bool flushStdout, const char *format, va_list argument ){

	#define BUF_SIZE 500

	char buffer[BUF_SIZE], userMessage[BUF_SIZE], errorText[BUF_SIZE];

	vsnprintf(userMessage, BUF_SIZE, format, argument);

	if (useError) {

	    snprintf(errorText, BUF_SIZE, "[%s %s]", (error > 0 && error <= MAX_ENAME) ? ename[error]: "?UNKNOWN?", strerror(error) );
	}
	else {

		snprintf(errorText, BUF_SIZE, ":");
	}

	snprintf(buffer, BUF_SIZE, "ERROR%s %s\n", errorText, userMessage);

	if (flushStdout){

	    fflush(stdout);
	}
	else {
	    ; /* MISRA C++ STANDARD */
	}

	fputs(buffer,stderr);

	fflush(stderr);
}

void errMsg ( const char *format, ... ){

    va_list argList ;

    int savedErrorNumber;

	/* errno is a macro present in errno.h file */
	savedErrorNumber = errno;

	va_start(argList, format);

	outputError(true, errno, true, format, argList );

	va_end(argList);

	errno = savedErrorNumber;
}

void errExit (const char * format, ...){

    va_list argList ;

    va_start (argList, format);

    outputError(true, errno, false, format, argList );

    va_end(argList);

	terminate(true);
}

void err_exit (const char *format, ... ){

    va_list argList;

	va_start(argList, format);

	outputError(true, errno, true, format, argList );

	va_end(argList);

	terminate(true);
}

void errExitEN(int errorNumber, const char *format, ... ){

	va_list argList;

	va_start(argList, format);

	outputError(true, errno, true, format, argList );

	va_end(argList);

	terminate(true);
}

void fatal (const char *format, ...){

    va_list argList;

	va_start(argList, format);

	outputError(false, 0, true, format, argList );

	va_end(argList);

	terminate(true);
}

void usageErr(const char *format, ... ){

    va_list argList;

    fflush(stdout);

	fprintf(stderr, "Usage: ");

	va_start(argList, format);

	vfprintf(stderr, format, argList);

	va_end(argList);

	fflush(stderr);

	exit (EXIT_FAILURE);
}

void cmdLineErr (const char * format, ...){

    va_list argList;

	fflush(stdout);

	fprintf(stderr, "Command Line usage error: ");

	va_start(argList, format);

	vfprintf(stderr, format , argList);

	va_end(argList);

	fflush(stderr);

	exit(EXIT_FAILURE);
}
