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
	ifTrue(SMALLER_OR_EQUAL(a,b));
	printS("True");
	endIf();
	
    // THE CODE GOES HERE

    // Debug
    analyse();
    // Debug

    return 0;
}

/* TO DO

? make #isZero array to contain the zero values and prevent [-]

*/
