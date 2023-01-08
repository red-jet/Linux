#include "headerfiles.h"
using namespace std;

int main() {

    /* lFileDescriptor_v_i8 is the file descriptor that holds the signed integer value of the open function */
    int8_t lFileDescriptor_v_i8 = open( "/home/Documents/test.txt" , O_APPEND );

    /* lReturnStatus_v_i8 variable holds the return value of the main function it is used to have only one return
     * statement in the whole function
     */
    int8_t lReturnStatus_v_i8 = -1 ;

    /* If the file descriptor encounters any error then it returns -1 and error number is set */
    if ( lFileDescriptor_v_i8 == -1 ) {

        /* Printing the error number with the help of the perror function  */
        /* perror( "Error " ) ; */

        /* strerror needs string.h and errno.h header file also you need to print the returning function */
        cout << strerror(errno) << endl ;
        lReturnStatus_v_i8 = -1 ;

    }
    else {

        lReturnStatus_v_i8 = 0 ;

    }

    return lReturnStatus_v_i8 ;
}
