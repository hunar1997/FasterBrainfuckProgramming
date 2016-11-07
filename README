Faster Brainfuck Programming FBP
This project is to make brainfuck language programming easier, faster and more powerful ..  everything is made out of functions making it very easy to port to other languages 

I made this using c++ but it's very easy to port to other languages

There is only one important file (FBP.cpp) .. you write your programmes at the bottom between the two comments in the main function and when you finish you compile it and the brainfuck code will be outputed.

The availale commands are here:

newVariable();  it will make a new variable and return an integer .. it takes an optional imput as the first value of the variable otherwise it'll have the value of 0
sample:   int a = newVariable(2);   makes a new variable called a with the value of 2

addN(location, number);   adds the number to the location (location is a variable) .. it should not be a negative number .. it'll automaticly chooses between using ++++ repeatedly or using multiplication to reduce the codes
sample:   addN(a, 10);    adds 10 to the value of the variable a

addV(from, to);   adds two variables together .. the result will be stored in (to) keeping the original value of (from) as it is
sample:   addV(a, b);   adds a and be together and storing the result in b

mulV(from, to);   same as addV but multiply

subV(from, to);   subtracts (from) from (to) and putting the result in (to)

move(from, to);   moves the value from (from) to (to) by resetting the value of (to) to 0 and moving the value of (from) to to and at the end the value of (from) will be 0

copy(from, to);   same as move but the value of (from) is not resetted to 0

swap(x, y);   swaps the variables values with each other

printV(location);    prints whatever is inside the (location) variable
sample:   int a = newVariable(104);
          printV(a);                thi will print the character h
          
printC(c);    takes an ASCII character and prints it .. it can be any character 'd', '%', '5'

resetVariable(location);    resets the variable to 0

movePointer(location);    moves the poiter to (location) variable by using > and <

wereToGo();   returns an integer containing the tape location that is not used by any variable (AKA available)

made by HUNAR OMAR in KURDISTAN
