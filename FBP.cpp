#include "Functions.h"

int main() {
	// Setup
	setup_the_memory();
	// Setup
	
	// THE CODE GOES HERE
	int x = newVariable(30);
	//int y = newVariable(3);
	//int z = newVariable(4);
	addN(x, -15);
	subN(x, -15);
	
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
 * addN now can receive negative numbers
 */

