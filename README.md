# Faster Brainfuck Programming FBP
# Version 0.1
This project is to make brainfuck language programming easier, faster and more powerful ..  everything is made out of functions making it very easy to port to other languages 

I made this using c++ but i used things that exist in every singe language 

There are only two important files (FBP.cpp and Functions.h) .. you write your programs in FBP.cpp inside main, and when you finish you compile it and the brainfuck code will be outputed.

## The sources i used

[Brainfuck Algorithms](https://esolangs.org/wiki/Brainfuck_algorithms/)  
 
[Brainfuck Visualizer](https://fatiherikli.github.io/brainfuck-visualizer/)  

## What's new!!
0.1:   
- Now you can put nested if-statements

## The availale commands are here  

|Code|Description|Example|
|------|-----|------|
|`newVariable();`|it will make a new variable and return an integer .. it takes an optional input as the first value of the variable otherwise it'll have the value of 0 | `int a = newVariable(2);`   makes a new variable called **a** with the value of 2|
|`addN(location, number);`|adds the **number** to the **location** (location is a variable) .. **now supports negative inputs :D** .. it'll automaticaly choose between using ++++ repeatedly or using multiplication to reduce the codes|`addN(a, 10);`    adds 10 to the value of the variable **a**|
|`addV(from, to);`|adds two variables together .. the result will be stored in **to** keeping the original value of **from** as it is|`addV(a, b);`   adds **a** and **b** together and storing the result in **b**|
|`mulV(from, to);`|same as addV but multiply||
|`divV(x, y);`|divide **x** by **y** and store the result in **x**  so it's like **(x=x/y)**  ||
|`subV(from, to);`|subtracts **from** from **to** and putts the result in **to** .. so **2-1** will be `subV(1, 2);` the **1** will be lost||
|`move(from, to);`|moves the value from **from** to **to** by resetting the value of **to** to **0** and moving the value of **from** to **to** .. and finally the value of **from** will be **0**||
|`copy(from, to);`|same as move but the value of **from** is not resetted to **0**||
|`getCopy(variable);`|create and return a new variable holding the same value as **variable** |`int newVariable = getCopy(another);`|
|`swap(x, y);`|swaps the variables values with each other||
|`printV(location);`|prints whatever is inside the **location** variable| `int a = newVariable(104);` `printV(a);`  this will print the character **h**|
|`printC(c);`|takes an ASCII character and prints it .. it can be any character 'd', '%', '5', character must be inside **'**||
|`printS(string);`|takes any ASCII character combinations and prints it, `printS("Hello World");` string must be inside **"**||
|`ifTrue(condition);`|used to create **if** statements and takes one **condition**, as discussed next. must be ended with `endIf();` | `ifTrue(SMALLER_OR_EQUAL(a,b));`|  
|`elseIf();`|codes between this and `endIf();` will be called when ifTrue condition is false.| `elseIf();` |  
|`endIf();`|used to end **if** statements and takes no arguments. | `endIf();` |
|`EQUAL(a, b);`|used as input to **if** statements, takes two variables and return true if they are equal | `EQUAL(a,b);` where **a** and **b** were made using `newVariable()`|
|`NOT_EQUAL(a, b);`|used as input to **if** statements, takes two variables and return true if they are not equal | `NOT_EQUAL(a,b);` where **a** and **b** were made using `newVariable()`|
|`GREATER(a, b);`|used as input to **if** statements, takes two variables and return true if a is greater than b | `GREATER(a,b);` where **a** and **b** were made using `newVariable()`|
|`GREATER_OR_EQUAL(a, b);`|used as input to **if** statements, takes two variables and return true if a is greater than or equal to b | `GREATER_OR_EQUAL(a,b);` where **a** and **b** were made using `newVariable()`|
|`SMALLER(a, b);`|used as input to **if** statements, takes two variables and return true if a is smaller than b | `SMALLER(a,b);` where **a** and **b** were made using `newVariable()`|
|`SMALLER_OR_EQUAL(a, b);`|used as input to **if** statements, takes two variables and return true if a is smaller than or equal to b | `SMALLER_OR_EQUAL(a,b);` where **a** and **b** were made using `newVariable()`|
|`resetVariable(location);`|resets the variable to **0**, (without freeing it)||
|`deleteVariable(location);`|resets the variable to **0**, and frees it||
|`movePointer(location);`|moves the poiter to **location** variable by using **>** and **<**||
|`wereToGo();`|returns an integer containing the tape location that is not used by any variable **(AKA available)**||
|`use(location);`|marks a location on memory as **used**||
|`free(location);`|marks a location on memory as **free**||
|`analyse();`|shows error with the number of memory leaks in your code **(for the compiler develover :D)**||

made by HUNAR OMAR in KURDISTAN  

**Enjoy brainfucking faster than before :D**

