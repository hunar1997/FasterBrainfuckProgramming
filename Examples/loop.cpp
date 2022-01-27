#include "../Functions.h"

int main() {
    // Setup (required)
    setup_the_memory();
    // Setup

    // THE CODE GOES HERE
    using namespace FBP;

    int a = newVariable(1);
    int z = newVariable(3);

    loop();     // loop runs with a=1 then a=2 then a=3 and when a==3 lastLoop is called so add makes a=4 then loop stops
        printC('L');
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

/* Output
    +>+++>+[>>+++++++[<+++++++++++>-]<-.[-]>>>[-]<<<<<<
    [>>>>>>+>>+<<<<<<<<-][-]>>>>>>>>[-<<<<<<<<+>>>>>>>>
    ]<[-]<<<<<<[>>>>>>+>+<<<<<<<-][-]>>>>>>>[-<<<<<<<+>
    >>>>>>]<<<<<+[>>>>[-<]<<]<[->>+<]>>[<<<->+>>[-]]<<<
    [>>>>>+>+<<<<<<-]>>>>>[<<<<<+>>>>>-]+<<<<<[-]>[-]>[
    -]>[-]>[-]>>[<<<<<<<[-]>>>>>>->[-]]<[-][-]>[-]<<<<<
    <<<<+>>]<<[-]>[-]
*/
