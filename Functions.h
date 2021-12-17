// Includes
#include <iostream>
#include <cmath>
#include <vector>
// -----------------------------------------

// Namespaces
using namespace std;
struct array;
struct cmp_result;
namespace FBP{
	void move(int from, int to);
	void copy(int from, int to);
    int getCopy(int variable);
	void addN(int location, int number);
	void subN(int location, int number);
    array newArray(int numItems);
    array newArray(vector<int> items);
	int newVariable();
	int newVariable(int number);
    void setVariable(int variable, int value);
    void resetVariable(int location);

	void addV(int from, int to, int store);
	void subV(int from, int to);
	void mulV(int from, int to);
	void divV(int x, int y);
	void swap(int x, int y);
	void printV(int location);
	void printC(char c);
	void printS(string s);

    cmp_result COMPARE(int num1, int num2);
	int EQUAL(int first_number, int second_number);
	int NOT_EQUAL(int first_number, int second_number);
	int GREATER(int first_number, int second_number);
	int GREATER_OR_EQUAL(int first_number, int second_number);
	int SMALLER(int first_number, int second_number);
	int SMALLER_OR_EQUAL(int first_number, int second_number);

    void ifTrue(int condition);
	void elseIf();
    void endIf();

    void loop();
    void endLoop();
    void breakLoop();
}
// -----------------------------------------
void setup_the_memory();
void movePointer(int location);

int wereToGo();
void use(int location);
void free(int location);

void deleteVariable(int location);
void deleteArray(array a);

// Defines
#define tapeSize 30000
#define nowhere -1
// -----------------------------------------

// Global Variables
bool available[tapeSize]; // The locations on memory used to store variables
int pointer = 0; // Pointer pointing to the current memory location

// -----------------------------------------

// The core functions
void setup_the_memory() {
    for (int i = 0; i < tapeSize; i++) {
        available[i] = true; // make every single memory byte available
    }
}
void use(int location) {
    available[location] = false;
}

void free(int location) {
    available[location] = true;
}
void movePointer(int location) { // moves the pointer to #location
    if (location > pointer)
        for (int i = pointer; i < location; i++) { // if i need to go forward
            cout << ">";
            pointer++;
        } else if (location < pointer)
        for (int i = pointer; i > location; i--) { // if i need to go backward
            cout << "<";
            pointer--;
        }
    if (pointer > tapeSize || pointer < 0) { // if we exceeded the memory boundaries
        cout << "\nError: Wrong tape position\n";
    }
}

struct array{
    int index;
    int size;
};
array FBP::newArray(int numItems){
    if (numItems==0){
        cout << "\nError:\vYOU CANNOT REQUEST ZERO ITEMS\n";
        return array{nowhere,nowhere};
    }

    for (int i = 0; i < tapeSize; i++) { // loop forward untill there is an available location
        if (available[i]) {
            bool isTheOne = true;
            for (int j=i; j<numItems+i; j++){
                if (not available[j]){
                    isTheOne = false;
                    break;
                }
            }
            if (isTheOne){
                for (int k=i; k<numItems+i; k++){
                    use(k);
                }
                return array {i, numItems};
            }
        }
    }
    cout << "\nError:\vThis error should never occur, it means that we used every location on the tape\n";
    return array{nowhere,nowhere};
}
array FBP::newArray(vector<int> items){
    array a = newArray(items.size());
    int i=0;
    for (int v=a.index; v<a.index+a.size; v++){
        addN(v, items[i++]);
    }
    return a;
}
int wereToGo() { // returns an empty location
    return FBP::newArray(1).index;
}

// reset variable to 0 but not delete it
void FBP::resetVariable(int location) {
    movePointer(location);
    cout << "[-]";
}
// -----------------------------------------

// reset variable to 0 and delete it
void deleteVariable(int location) {
	movePointer(location);
	free(location);
	cout << "[-]";
}

void deleteArray(array a) {
    movePointer(a.index);
    for (int i=a.index; i<a.index+a.size; i++){
        deleteVariable(i);
    }
}

void FBP::move(int from, int to) {
    resetVariable(to);
    movePointer(from);
    cout << "[-";
    movePointer(to);
    cout << "+";
    movePointer(from);
    cout << "]";
}

void FBP::copy(int from, int to) {
    int temp = wereToGo();

    movePointer(to);
    cout << "[-]";
    movePointer(from);
    cout << "[";
    movePointer(to);
    cout << "+";
    movePointer(temp);
    cout << "+";
    movePointer(from);
    cout << "-]";

    move(temp, from);

    free(temp);
}

int FBP::getCopy(int variable){
	int result = FBP::newVariable();
	FBP::copy(variable, result);
	return result;
}

// add a value to a variable
void FBP::addN(int location, int number) {
    if (number==0) return;
    int absNumber = abs(number);
    if (absNumber < 15) {
        movePointer(location);
        for (int i = 0; i < absNumber; i++){
            if (number>0) cout << "+";
            if (number<0) cout << "-";
        }
    } else {
        int n1 = 500;
        int n2 = 500;
        for (int i = 1; i < absNumber; i++) {
            for (int j = 1; j < absNumber; j++) {
                if (i * j == absNumber || i * j == absNumber - 1 || i * j == absNumber + 1) {
                    if (i + j < n1 + n2) {
                        n1 = i;
                        n2 = j;
                    }
                }
            }
        }
        short tt = 0;
        if (n1 * n2 != absNumber) {
            if (n1 * n2 == absNumber + 1) tt = -1;
            if (n1 * n2 == absNumber - 1) tt = 1;
        }
        int temp1 = wereToGo();
        movePointer(temp1);
        
        for (; n1 > 0; n1--) cout << "+";
        cout << "[";
        movePointer(location);
        for (; n2 > 0; n2--) if (number>0) cout << "+"; else cout << "-";
        movePointer(temp1);
        cout << "-]";
        if (tt != 0) {
            movePointer(location);
            if (tt == 1) cout << "+";
            else if (tt == -1) cout << "-";
        }

        if (n1 == 500 || n2 == 500) cout << "\nErro: I hope i dont see this error\n";
        free(temp1);
    }
}

// subtract a value from a variable
void FBP::subN(int location, int number) {
    addN(location, -number);
}

// returns a new available position and makes it unavailable to prevent overwrite
int FBP::newVariable() {
    int place = wereToGo();
    return place;
}

// same as above but it'll also assign it to #number
int FBP::newVariable(int number) {
    if (number==0) return newVariable();
    int place = wereToGo();
    movePointer(place);
    addN(place, number);
    return place;
}

// set a variable to a value by resetting it then adding the value
void FBP::setVariable(int variable, int value){
    resetVariable(variable);
    addN(variable,value);
}

void FBP::addV(int from, int to, int store) {
    if (available[from] || available[to]) {
        cout << "\nError: one or both inputs were not variables\n";
        return;
    }
    if (store == to) {
		int temp = FBP::newVariable();

        movePointer(from);
        cout << "[";
        movePointer(to);
        cout << "+";
        movePointer(temp);
        cout << "+";
        movePointer(from);
        cout << "-]";
        movePointer(temp);
        cout << "[";
        movePointer(from);
        cout << "+";
        movePointer(temp);
        cout << "-]";

        free(temp);
    } else if (store == from) {

        int temp = newVariable();

        movePointer(to);
        cout << "[";
        movePointer(from);
        cout << "+";
        movePointer(temp);
        cout << "+";
        movePointer(to);
        cout << "-]";
        movePointer(temp);
        cout << "[";
        movePointer(to);
        cout << "+";
        movePointer(temp);
        cout << "-]";

        free(temp);
    } else {
        resetVariable(store);
        copy(from, store);
        addV(to, store, store);
    }
}

void FBP::subV(int from, int to) {
    if (!available[from] && !available[to]) {
        int temp = newVariable();

        movePointer(from);
        cout << "[";
		movePointer(to);
        cout << "-";
        movePointer(temp);
        cout << "+";
		movePointer(from);
        cout << "-]";
        movePointer(temp);
        cout << "[";
		movePointer(from);
        cout << "+";
        movePointer(temp);
        cout << "-]";

		// delete variable, no need to reset		it's already zero .. i should optimize that by adding isZero array
        available[temp] = true;
    } else {
        cout << "one or both inputs were not variables";
    }
}

void FBP::mulV(int from, int to) {
    if (!available[from] && !available[to]) {
        int temp = newVariable();
        int temp1 = newVariable();

        movePointer(to);
        cout << "[";
        movePointer(temp1);
        cout << "+";
        movePointer(to);
        cout << "-]";
        movePointer(temp1);
        cout << "[";
        movePointer(from);
        cout << "[";
        movePointer(to);
        cout << "+";
        movePointer(temp);
        cout << "+";
        movePointer(from);
        cout << "-]";
        movePointer(temp);
        cout << "[";
        movePointer(from);
        cout << "+";
        movePointer(temp);
        cout << "-]";
        movePointer(temp1);
        cout << "-]";
	
		
        free(temp); // delete variable, no need to reset
        free(temp1); // delete variable, no need to reset
    } else {
        cout << "one or both inputs were not variables";
    }
}

void FBP::divV(int x, int y) {
    if (!available[x] && !available[y]) {
        int temp0 = newVariable();
        int temp1 = newVariable();
        int temp2 = newVariable();
        int temp3 = newVariable();

        movePointer(x);
        cout << "[";
        movePointer(temp0);
        cout << "+";
        movePointer(x);
        cout << "-]";
        movePointer(temp0);
        cout << "[";
        movePointer(y);
        cout << "[";
        movePointer(temp1);
        cout << "+";
        movePointer(temp2);
        cout << "+";
        movePointer(y);
        cout << "-]";
        movePointer(temp2);
        cout << "[";
        movePointer(y);
        cout << "+";
        movePointer(temp2);
        cout << "-]";
        movePointer(temp1);
        cout << "[";
        movePointer(temp2);
        cout << "+";
        movePointer(temp0);
        cout << "-[";
        movePointer(temp2);
        cout << "[-]";
        movePointer(temp3);
        cout << "+";
        movePointer(temp0);
        cout << "-]";
        movePointer(temp3);
        cout << "[";
        movePointer(temp0);
        cout << "+";
        movePointer(temp3);
        cout << "-]";
        movePointer(temp2);
        cout << "[";
        movePointer(temp1);
        cout << "-";
        cout << "[";
        movePointer(x);
        cout << "-";
        movePointer(temp1);
        cout << "[-]]+";
        movePointer(temp2);
        cout << "-]";
        movePointer(temp1);
        cout << "-]";
        movePointer(x);
        cout << "+";
        movePointer(temp0);
        cout << "]";
		
		free(temp0);
		free(temp1);
		free(temp2);
		free(temp3);
    } else {
        cout << "one or both inputs were not variables";
    }
}

void FBP::swap(int x, int y) {
    if (!available[x] && !available[y]) {
        int temp = newVariable();

        movePointer(x);
        cout << "[";
        movePointer(temp);
        cout << "+";
        movePointer(x);
        cout << "-]";
        movePointer(y);
        cout << "[";
        movePointer(x);
        cout << "+";
        movePointer(y);
        cout << "-]";
        movePointer(temp);
        cout << "[";
        movePointer(y);
        cout << "+";
        movePointer(temp);
        cout << "-]";

        free(temp); // delete variable, no need to reset
    } else {
        cout << "one or both inputs were not variables";
    }
}

// print value in the variable as ASCII
void FBP::printV(int location) {
    movePointer(location);
    cout << ".";
}

// print a character (any ASCII) character in ' '
void FBP::printC(char c) {
    int temp = newVariable();

    addN(temp, c);
    movePointer(temp);
    cout << ".";

	deleteVariable(temp);
}

// print a string
void FBP::printS(string s) {
    struct part{
        bool skip=true;
        int val;
        int index=nowhere;
    };
    part parts[6] = {{true,32},{true,53},{true,72},{true,89},{true,103},{true,117}};

//    int space=32;   // 32  => 47
//    int number=53;  // 48  => 64
//    int big1=72;    // 65  => 80
//    int big2=89;    // 81  => 96
//    int small1=103; // 97  => 110
//    int small2=117; // 111 => 126

	if (s.length()==1){
		printC(s.at(0));
		return;
	}


    vector<int> memory;
	for (int i=0; i<s.size(); i++){
		char c = s.at(i);
		
        if (c>=32 and c<=47 and parts[0].skip){
            parts[0].index=memory.size();
            memory.push_back(parts[0].val);
            parts[0].skip = false;
        }else if (c>=48 and c<=64 and parts[1].skip){
            parts[1].index=memory.size();
            memory.push_back(parts[1].val);
            parts[1].skip = false;
        }else if (c>=65 and c<=80 and parts[2].skip){
            parts[2].index=memory.size();
            memory.push_back(parts[2].val);
            parts[2].skip = false;
        }else if (c>=81 and c<=96 and parts[3].skip){
            parts[3].index=memory.size();
            memory.push_back(parts[3].val);
            parts[3].skip = false;
        }else if (c>=97 and c<=110 and parts[4].skip){
            parts[4].index=memory.size();
            memory.push_back(parts[4].val);
            parts[4].skip = false;
        }else if (c>=111 and c<=126 and parts[5].skip){
            parts[5].index=memory.size();
            memory.push_back(parts[5].val);
            parts[5].skip = false;
        }
	}

    array workingArea = newArray(memory);
    for (int i=0; i<6;i++){
        parts[i].index += workingArea.index;
    }

	for (int i=0; i<s.size(); i++){
		char c = s.at(i);

        part *chosen_one;

        if (c>=32 and c<=47){
            chosen_one = &parts[0];
        }else if (c>=48 and c<=64){
            chosen_one = &parts[1];
        }else if (c>=65 and c<=80){
            chosen_one = &parts[2];
        }else if (c>=81 and c<=96){
            chosen_one = &parts[3];
        }else if (c>=97 and c<=110){
            chosen_one = &parts[4];
        }else if (c>=111 and c<=126){
            chosen_one = &parts[5];
        }

        if (c == chosen_one->val){
            movePointer(chosen_one->index);
        }else{
            int mag = c - chosen_one->val;
            chosen_one->val = c;
            FBP::addN(chosen_one->index, mag);
        }
        cout << ".";
	}
    deleteArray(workingArea);
}


int priv_n1 = nowhere;
int priv_n2 = nowhere;
struct cmp_result{  // maybe in future, every pair has its own result saved
    int equal = nowhere;
    int greater = nowhere;
    int smaller = nowhere;
} priv_result;
array priv_array;
cmp_result FBP::COMPARE(int num1, int num2){
    deleteArray(priv_array);

    priv_array = FBP::newArray(5);
    cout << "allocated 5 from " << priv_array.index;
    int r1 = priv_array.index;  // r1 = n1 == n2
    int r2 = r1+1;              // r2 = n1 > n2
    int r3 = r2+1;              // r3 = n1 < n2
    int n1 = r3+1;
    int n2 = n1+1;
    priv_result={r1,r2,r3};
    FBP::copy(num1, n1);
    FBP::copy(num2, n2);
    movePointer(r1);
    cout << "+[>>>>[-<]<<]<[->>+<]>>[<<<->+>>[-]]";    // dangerous two lines but necessary
    pointer = n1;
    return cmp_result{r1,r2,r3};
}

int FBP::EQUAL(int first_number, int second_number){
    return FBP::COMPARE(first_number, second_number).equal;
}

int FBP::NOT_EQUAL(int first_number, int second_number){
    int result = FBP::EQUAL(first_number, second_number);
	int temp0 = newVariable();
    movePointer(result);
    cout << "[";
    FBP::addN(temp0,1);
    resetVariable(result);
    cout << "]+";
    movePointer(temp0);
    cout << "[";
    FBP::subN(result,1);
    FBP::subN(temp0,1);
    cout << "]";
	free(temp0);
	return result;
}

int FBP::GREATER(int first_number, int second_number){
    return FBP::COMPARE(first_number, second_number).greater;
}

int FBP::GREATER_OR_EQUAL(int first_number, int second_number){
    FBP::addN(first_number, 1);
    int result = FBP::GREATER(first_number, second_number);
    FBP::subN(first_number, 1);
    return result;
}

int FBP::SMALLER(int first_number, int second_number){
    return FBP::COMPARE(first_number, second_number).smaller;
}

int FBP::SMALLER_OR_EQUAL(int first_number, int second_number){
    FBP::subN(first_number, 1);
    int result = FBP::SMALLER(first_number, second_number);
    FBP::addN(first_number, 1);
    return result;
}


struct if_data{
    int temp0;
    int temp1;
    bool elseExists=false;
};
vector<if_data> if_list;

void FBP::ifTrue(int condition){
	int temp0 = newVariable();
	int temp1 = newVariable();
	
	if_data this_if;
	this_if.temp0 = temp0;
	this_if.temp1 = temp1;
	if_list.push_back(this_if);

	movePointer(condition);
	cout << "[";
	movePointer(temp0);
	cout << "+";
	movePointer(temp1);
	cout << "+";
	movePointer(condition);
	cout << "-]";
	movePointer(temp0);
	cout << "[";
	movePointer(condition);
	cout << "+";
	movePointer(temp0);
	cout << "-]+";
	movePointer(temp1);
    cout << "[";
}
void FBP::elseIf(){
    if_list.back().elseExists=true;
	int temp0 = if_list.back().temp0;
	int temp1 = if_list.back().temp1;
	movePointer(temp0);
	cout << "-";
	movePointer(temp1);
	cout << "[-]]";
	movePointer(temp0);
	cout << "[";
}
void FBP::endIf(){
if (not if_list.back().elseExists) elseIf();
	int temp0 = if_list.back().temp0;
	int temp1 = if_list.back().temp1;
	movePointer(temp0);
	cout << "-]";
	deleteVariable(temp0);
	deleteVariable(temp1);
    if_list.pop_back();
}


vector<int> while_data;
void FBP::loop(){
    int cond = newVariable(1);
    cout << "cond" << cond;
    while_data.push_back(cond);
    movePointer(cond);
    cout << "[";
}

void FBP::endLoop(){
    movePointer(while_data.back());
    cout << "checking";
    cout << "]";
    while_data.pop_back();
}

void FBP::breakLoop(){
    resetVariable(while_data.back());
}


void analyse() {
    vector<int> leaks;
    for (int i = 0; i < tapeSize; i++) {
        if (available[i] == false) {
            leaks.push_back(i);
        }
    }
    if (leaks.size() > 0) {
        cout << endl << "Memory Leak Detected: " << leaks.size() << " memory not freed" << endl;
    }
    for (int i=0; i<leaks.size(); i++){
        cout << leaks[i] << " ";
    }
    cout << endl;
}
// The core functions

