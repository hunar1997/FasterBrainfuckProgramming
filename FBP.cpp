#include "Functions.h"

int main() {
    // Setup (required)
    setup_the_memory();
    // Setup

    // THE CODE GOES HERE
	using namespace FBP;


    int a = newVariable(1);
    int z = newVariable(3);

    loop();
        printC('T');
        ifTrue(EQUAL(a,z));
            lastLoop();
        endIf();
        addN(a,1);
    endLoop();

    deleteVariable(a);
    deleteVariable(z);


    // THE CODE GOES HERE

    // Debug
	// shows number of memory leaks that are not free(); ed
    analyse();
    // Debug

    return 0;
}

/* TO DO

 make #isZero array to contain the zero values and prevent [-]
 use a consistent format in naming functions

 dont delete the memory for print and reuse it, make freeStrings() at end

 make freeEverything() to free everything instead of deleting one by one

 subN is absent in the documentation

 add NOT_ZERO
*/
