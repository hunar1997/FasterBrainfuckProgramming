#include "../Functions.h"

int main() {
    // Setup (required)
    setup_the_memory();
    // Setup

    // THE CODE GOES HERE
	using namespace FBP;
    int age = newVariable(20);
    int age1 = newVariable(12);
    int age2 = newVariable(30);

    printS("You are ");
    ifTrue(SMALLER_OR_EQUAL(age, age1));
        printS("a child.");
    elseIf();
        ifTrue(SMALLER_OR_EQUAL(age, age2));
            printS("young.");
        elseIf();
            printS("Old");
        endIf();
    endIf();
    deleteVariable(age);
    deleteVariable(age1);
    deleteVariable(age2);
    // THE CODE GOES HERE

    // Debug
	// shows number of memory leaks that are not free(); ed
    analyse();
    // Debug

    return 0;
}
