#include "Functions.h"

int main() {
	// Setup
	setup_the_memory();
	// Setup
	
	// THE CODE GOES HERE
	int x = newVariable(2);
	int y = newVariable(3);
	int z = newVariable(4);
	addV(x, y, z);
	
	// THE CODE GOES HERE
	
	// Debug
	analyse();
	// Debug
	
	return 0;
}

/* TO NOTE

 * added #use and #free
 * did some optimization
 * make #isZero array to contain the zero values and prevent [-]
 * Changed addV
 */

