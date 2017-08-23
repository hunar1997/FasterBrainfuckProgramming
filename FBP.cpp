#include "Functions.h"

int main() {
    // Setup
    setup_the_memory();
    // Setup

    // THE CODE GOES HERE
	using namespace FBP;
	int a = newVariable(3);
	int b = newVariable(4);
	int z = newVariable();
	ifTrue(NOT_EQUAL(a,b));
	addN(z, 10);
	endIf();
	
    // THE CODE GOES HERE

    // Debug
    analyse();
    // Debug

    return 0;
}

/* TO NOTE

 ? make #isZero array to contain the zero values and prevent [-]

 */
