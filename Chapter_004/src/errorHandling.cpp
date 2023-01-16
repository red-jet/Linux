#include "../headerFiles/headerMain.h"

static void terminate (bool aExit_b) {

	int8_t *lString_p8;

	lString_p8 = getenv("EF_DUMPCORE");

	if (lString_p8 != NULL && *lString_p8 != '\0'){
		abort();
	}
	else if (aExit_b){
		exit(EXIT_FAILURE);
	}
	else
		_exit(EXIT_FAILURE);
}



