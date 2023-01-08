#include<iostream>
#include<gnu/libc-version.h>
using namespace std;

int main()
{
	const uint8_t *lVersionValue_p_u8 = ( const uint8_t* ) gnu_get_libc_version() ; 

	cout << "GNU Library version : " << lVersionValue_p_u8 << endl ; 
}
