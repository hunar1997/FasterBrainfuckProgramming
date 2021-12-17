#include "Functions.h"

int main() {
    // Setup (required)
    setup_the_memory();
    // Setup

    // THE CODE GOES HERE
	using namespace FBP;


    int a = newVariable(3);
    int z = newVariable(3);

    loop();
        printC('T');
        ifTrue(EQUAL(a,z));
            breakLoop();
            cout << "check";
        endIf();
    endLoop();
    /*
    PLEASE READ
    I finally figure out that you shouldn't free memory in loop because
    you use it in the next iteration, so I have to change the entire prject
    so the user pre allocates memory at the start then assigns them to functions
    that need variabels. However it's terrible for the syntax since they need to pass
    temporaries as well :(
    I have an idea, detect if inside function, then dont free them :)
    */

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

 fix the 5 memory issues by making a freeComparison() function

 dont delete the memory for print and reuse it, make freeStrings() at end

 make freeEverything() to free everything instead of deleting one by one

 subN is absent in the documentation

 add NOT_ZERO
*/
