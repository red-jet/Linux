#include "../headerFiles/headerFiles.h"
#include "./errorHandling.cpp"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif /* BUFFER_SIZE */

using namespace std;

int main (int argc, char *argv[]) {

    int32_t lInputFileDescriptor_i32 = 0, lOutputFileDescriptor_i32 = 0, lOpenFlag_i32 = 0;
    mode_t lFilePermissions;


    if ( argc != 3 ) {
        /* Enter here if arguments are not equal to 3 */
        cout << " cp: missing destination file operand after '" << argv[1] << "'" << endl;
        cout << "Try 'cp --help' for more information." << endl;
        usageErr("%s Old file new file \n", argv[0]);

    }

    lInputFileDescriptor_i32 = open ( argv[1], O_RDONLY );


    if ( lInputFileDescriptor_i32 == -1 ) {

        /* Enters here if any error is encountered during the file opening */
        errExit ("opening file %s ", argv[1]);
    }
    else {
        ; /* MISRA C++ STANDARD */
    }

    /* Enters here if the file is opened successfully */
    lOpenFlag_i32		= 	O_CREAT | O_WRONLY | O_TRUNC ;

    lFilePermissions 	= 	S_IRUSR | S_IWUSR | S_IRGRP | \
                            S_IROTH | S_IWOTH ;

    lOutputFileDescriptor_i32 = open ( argv[1], lOpenFlag_i32, lFilePermissions );

    if (lOutputFileDescriptor_i32 == -1 ){

        /* Enters here if any error is encountered during the file opening */
        errExit("opening file %s", argv[2]);

    }
    else {
        ; /* MISRA C++ Standard */
    }

    ssize_t lNumberOfBytesRead;
    int8_t lBuffer_i8[BUF_SIZE];

    while ( ( lNumberOfBytesRead = read( lInputFileDescriptor_i32, lBuffer_i8 , BUF_SIZE) ) > 0) {

        if ( write (lOutputFileDescriptor_i32 , lBuffer_i8, lNumberOfBytesRead ) != lNumberOfBytesRead ){
                       fatal(" Couldn't write the whole buffer ");
        }
    }

    if (lNumberOfBytesRead == -1 ) {

        errExit("read");
    }
    else {
        ; /* MISRA C++ Standard */
    }

    if (close (lInputFileDescriptor_i32) == -1 ) {

        errExit("close input");
    }
    else {
        ;
    }

    if (close (lOutputFileDescriptor_i32) == -1 ) {

        errExit("close output");
    }
    else {
        ;
    }

    exit(EXIT_SUCCESS);
    
    return 0;

}
