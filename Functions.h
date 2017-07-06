// Includes
#include <iostream>
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
        available[i] = true;
    }
}

void movePointer(int location) { // moves the pointer to #location
    if (location > pointer)
        for (int i = pointer; i < location; i++) {
            cout << ">";
            pointer++;
        } else if (location < pointer)
        for (int i = pointer; i > location; i--) {
            cout << "<";
            pointer--;
        }
    if (pointer > tapeSize || pointer < 0)
        cout << "Error, illigal tape position";
}

int wereToGo() { // returns an empty location
    for (int i = 0; i < tapeSize; i++)
        if (available[i]) return i;

    cout << "This error should never occur, it means that we used every location on the tape\n";
    return false;
}

void resetVariable(int location) { // reset variable to 0 but not depet it
    movePointer(location);
    cout << "[-]";
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
    available[temp] = false;

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
    movePointer(temp);
    cout << "[";
    movePointer(from);
    cout << "+";
    movePointer(temp);
    cout << "-]";

    available[temp] = true;
}

void addN(int location, short number) { // add a value to a variable
    movePointer(location);
    if (number < 15) {
        for (int i = 0; i < number; i++)
            cout << "+";
    } else {
        int n1 = 500;
        int n2 = 500;
        for (int i = 1; i < number; i++) {
            for (int j = 1; j < number; j++) {
                if (i * j == number || i * j == number - 1 || i * j == number + 1) {
                    if (i + j < n1 + n2) {
                        n1 = i;
                        n2 = j;
                    }
                }
            }
        }
        short tt = 0;
        if (n1 * n2 != number) {
            if (n1 * n2 == number + 1) tt = -1;
            if (n1 * n2 == number - 1) tt = 1;
        }
        int temp1 = wereToGo();
        available[temp1] = false;
        movePointer(temp1);
        for (; n1 > 0; n1--) cout << "+";
        cout << "[";
        movePointer(location);
        for (; n2 > 0; n2--) cout << "+";
        movePointer(temp1);
        cout << "-]";
        if (tt != 0) {
            movePointer(location);
            if (tt == 1) cout << "+";
            else if (tt == -1) cout << "-";
        }

        if (n1 == 500 || n2 == 500) cout << "i hope i dont see this error";
        available[temp1] = true;
    }
}

int newVariable() { // returns a new available position and makes it unavailable to prevent overwrite
    int place = wereToGo();
    available[place] = false;
    return place;
}

int newVariable(int number) { // same as above but it'll also assign it to #number
    int place = wereToGo();
    available[place] = false;
    movePointer(place);
    addN(place, number);
    return place;
}

void addV(int from, int to) {
    if (!available[from] && !available[to]) {
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

        available[temp] = true; // delete variable, no need to reset
    } else {
        cout << "one or both inputs were not variables";
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