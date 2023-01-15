#include "../headerFiles/headerMain.h"
using namespace std;

int main (int argc, char *argv[]) {

	int32_t lInputFileDescriptor_i32 = 0, lOutputFileDescriptor_i32 = 0, lOpenFlag_i32 = 0;
	mode_t lFilePermissions;
	ssize_t lNumberOfBytesRead;
	bool lReturn_b = false;

	if ( argc != 3 ) {
		/* Enter here if arguments are not equal to 3 */
		cout << " cp: missing destination file operand after '" << argv[1] << "'" << endl;
		cout << "Try 'cp --help' for more information." << endl;
		lReturn_b = true ;
	}

	else {
		/* Enters here if argument is equal to 3 */

		lInputFileDescriptor_i32 = open ( argv[1], O_RDONLY );

		if ( lInputFileDescriptor_i32 == -1 ) {

			/* Enters here if any error is encountered during the file opening */
			perror ("Error: ");
			lReturn_b = true;
		}

		else {

			/* Enters here if the file is opened successfully */

		}
	}


}
