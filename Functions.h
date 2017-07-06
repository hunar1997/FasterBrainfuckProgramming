// Includes
#include <iostream>
#include <cmath>
// Includes

// Namespaces
using namespace std;
// Namespaces

// Defines
#define tapeSize 30000
// Defines

// Global Variables
bool available[tapeSize]; // The locations on memory used to store variables
int pointer = 0; // Pointer pointing to the current memory location
// Global Variables


// The core functions

void setup_the_memory() {
    for (int i = 0; i < tapeSize; i++) {
        available[i] = true; // make every single memory byte available
    }
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

int wereToGo() { // returns an empty location
    for (int i = 0; i < tapeSize; i++) { // loop forward untill there is an available location
        if (available[i]) {
            return i;
        }
    }

    cout << "\nError: This error should never occur, it means that we used every location on the tape\n";
    return false;
}

void resetVariable(int location) { // reset variable to 0 but not delete it
    movePointer(location);
    cout << "[-]";
}

void use(int location) {
    available[location] = false;
}

void free(int location) {
    available[location] = true;
}

void move(int from, int to) {
    resetVariable(to);
    movePointer(from);
    cout << "[-";
    movePointer(to);
    cout << "+";
    movePointer(from);
    cout << "]";
}

void copy(int from, int to) {
    int temp = wereToGo();
    use(temp);

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

void addN(int location, int number) { // add a value to a variable
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
        use(temp1);
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

void subN(int location, int number) { // subtract a value from a variable
    addN(location, -number);
}

int newVariable() { // returns a new available position and makes it unavailable to prevent overwrite
    int place = wereToGo();
    use(place);
    return place;
}

int newVariable(int number) { // same as above but it'll also assign it to #number
    int place = wereToGo();
    use(place);
    movePointer(place);
    addN(place, number);
    return place;
}

void addV(int from, int to, int store) {
    if (available[from] || available[to]) {
        cout << "\nError: one or both inputs were not variables\n";
        return;
    }
    if (store == to) {
        int temp = newVariable();

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

void subV(int from, int to) {
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

        available[temp] = true; // delete variable, no need to reset
    } else {
        cout << "one or both inputs were not variables";
    }
}

void mulV(int from, int to) {
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

        available[temp] = true; // delete variable, no need to reset
        available[temp1] = true; // delete variable, no need to reset
    } else {
        cout << "one or both inputs were not variables";
    }
}

void divV(int x, int y) {
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

        available[temp0] = true;
        available[temp1] = true;
        available[temp2] = true;
        available[temp3] = true;
    } else {
        cout << "one or both inputs were not variables";
    }
}

void swap(int x, int y) {
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

        available[temp] = true; // delete variable, no need to reset
    } else {
        cout << "one or both inputs were not variables";
    }
}

void printV(int location) { // print ASCII value
    movePointer(location);
    cout << ".";
}

void printC(char c) { // print a character (any ASCII) character in ' '
    int temp = newVariable();

    addN(temp, c);
    movePointer(temp);
    cout << ".";
    resetVariable(temp);

    available[temp] = true;
}

void printS(string s) { // print a string
    int tmpVal = s.at(0);
    int space = newVariable(32);
    int tmp = newVariable(tmpVal);

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 32) {
            movePointer(space);
            cout << ".";
            continue;
        }
        if (tmpVal == s.at(i)) {
            cout << ".";
        } else if (tmpVal < s.at(i)) {
            int mag = s.at(i) - tmpVal;
            tmpVal += mag;
            addN(tmp, mag);
            movePointer(tmp);
            cout << ".";
        } else if (tmpVal > s.at(i)) {
            int mag = tmpVal - s.at(i);
            int tt = newVariable(mag);
            tmpVal -= mag;

            subV(tt, tmp);
            movePointer(tmp);
            cout << ".";

            // free this variable
            resetVariable(tt);
            available[tt] = true;
        }
    }
    resetVariable(tmp);
    resetVariable(space);
    available[space] = true;
    available[tmp] = true;
}

void analyse() {
    int ml = 0;
    for (int i = 0; i < tapeSize; i++) {
        if (available[i] == false) {
            ml++;
        }
    }
    if (ml > 0) {
        cout << endl << "Memory Leak Detected: " << ml << " memories not freed" << endl;
    }
}
// The core functions