#include "Functions.h"

int main() {
    // Setup (required)
    setup_the_memory();
    // Setup

    // THE CODE GOES HERE
	using namespace FBP;
	// this is an overkill example since print takes along time
	int a = newVariable(2); // [bug] when a is bigger it takes a ton of time
	int b = newVariable(3);
	cout << "\n";
	int r = GREATER_OR_EQUAL(a, b);
	cout << endl << r << endl;
    // THE CODE GOES HERE

    // Debug
	// shows number of memory leaks that are not free(); ed
    analyse();
    // Debug

    return 0;
}

/* TO DO

? make #isZero array to contain the zero values and prevent [-]

*/
