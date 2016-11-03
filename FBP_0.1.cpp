// rules
// Variable must be stored in int
// Only works with positive numbers
#include <stdio.h>

#define tapeSize 30000
// header stuff ends here

bool available[tapeSize];
int pointer = 0;

void setup(){
	for(int i=0 ; i<tapeSize ; i++)
		available[i]=true;
}

void movePointer(int location){ // moves the pointer to #location
	if(location>pointer)
		for(int i=pointer;i<location;i++){
	    	printf(">");
	    	pointer++;
	    }
	else if(location<pointer)
		for(int i=pointer;i>location;i--){
	    	printf("<");
	    	pointer--;
	    }
	if(pointer>tapeSize||pointer<0)
		printf("Error, illigal tape position");
}

int wereToGo(){ // returns an empty location
	for(int i=0 ; i<tapeSize ; i++)
		if(available[i]) return i;
	
	printf("This error should never occur, it means that we used every location on the tape\n");
	return false;
}

void resetVariable(int location){ // reset variable to 0 but not depet it
	movePointer(location);
	printf("[-]");
}


void move(int from, int to){
	resetVariable(to);
	movePointer(from);
	printf("[-");
	movePointer(to);
	printf("+");
	movePointer(from);
	printf("]");
}

void copy(int from, int to){
	int temp = wereToGo();
	available[temp]=false;
	
	movePointer(to);
	printf("[-]");
	movePointer(from);
	printf("[");
	movePointer(to);
	printf("+");
	movePointer(temp);
	printf("+");
	movePointer(from);
	printf("-]");
	movePointer(temp);
	printf("[");
	movePointer(from);
	printf("+");
	movePointer(temp);
	printf("-]");
	
	available[temp]=true;
}

void addN(int location, short number){ // add a value to a variable
	movePointer(location);
	if(number<15){
		for(int i=0 ; i<number ; i++)
			printf("+");
	}else{
		int n1=500;
		int n2=500;
		for(int i=1 ; i<number ; i++){
			for(int j=1 ; j<number ; j++){
				if(i*j==number||i*j==number-1||i*j==number+1){
					if(i+j<n1+n2){
						n1=i;
						n2=j;
					}
				}
			}
		}
		short tt=0;
		if(n1*n2!=number){
			if(n1*n2==number+1) tt=-1;
			if(n1*n2==number-1) tt=1;
		}
		int temp1=wereToGo();
		available[temp1]=false;
		movePointer(temp1);
		for(;n1>0;n1--) printf("+");
		printf("[");
		movePointer(location);
		for(;n2>0;n2--) printf("+");
		movePointer(temp1);
		printf("-]");
		if(tt!=0){
			movePointer(location);
			if(tt==1) printf("+");
			else if(tt==-1) printf("-");
		}
		
		if(n1==500||n2==500) printf("i hope i dont see this error");
		available[temp1]=true;
	}
}

int newVariable(){ // returns a new available position and makes it unavailable to prevent overwrite
	int place = wereToGo();
	available[place]=false;
	return place;
}
int newVariable(int number){ // same as above but it'll also assign it to #number
	int place = wereToGo();
	available[place]=false;
	movePointer(place);
	addN(place, number);
	return place;
}

void addV(int from, int to){
	if(!available[from] && !available[to]){
		int temp = newVariable();
		
		movePointer(from);
		printf("[");
		movePointer(to);
		printf("+");
		movePointer(temp);
		printf("+");
		movePointer(from);
		printf("-]");
		movePointer(temp);
		printf("[");
		movePointer(from);
		printf("+");
		movePointer(temp);
		printf("-]");
		
		available[temp]=true; // delete variable, no need to reset
	}else{
		printf("one or both inputs were not variables");
	}
}

void subV(int from, int to){
	if(!available[from] && !available[to]){
		int temp = newVariable();
		
		movePointer(from);
		printf("[");
		movePointer(to);
		printf("-");
		movePointer(temp);
		printf("+");
		movePointer(from);
		printf("-]");
		movePointer(temp);
		printf("[");
		movePointer(from);
		printf("+");
		movePointer(temp);
		printf("-]");
		
		available[temp]=true; // delete variable, no need to reset
	}else{
		printf("one or both inputs were not variables");
	}
}

void mulV(int from, int to){
	if(!available[from] && !available[to]){
		int temp = newVariable();
		int temp1 = newVariable();
		
		movePointer(to);
		printf("[");
		movePointer(temp1);
		printf("+");
		movePointer(to);
		printf("-]");
		movePointer(temp1);
		printf("[");
		movePointer(from);
		printf("[");
		movePointer(to);
		printf("+");
		movePointer(temp);
		printf("+");
		movePointer(from);
		printf("-]");
		movePointer(temp);
		printf("[");
		movePointer(from);
		printf("+");
		movePointer(temp);
		printf("-]");
		movePointer(temp1);
		printf("-]");
		
		available[temp]=true; // delete variable, no need to reset
		available[temp1]=true; // delete variable, no need to reset
	}else{
		printf("one or both inputs were not variables");
	}
}

void swap(int x, int y){
	if(!available[x] && !available[y]){
		int temp = newVariable();
		
		movePointer(x);
		printf("[");
		movePointer(temp);
		printf("+");
		movePointer(x);
		printf("-]");
		movePointer(y);
		printf("[");
		movePointer(x);
		printf("+");
		movePointer(y);
		printf("-]");
		movePointer(temp);
		printf("[");
		movePointer(y);
		printf("+");
		movePointer(temp);
		printf("-]");
		
		available[temp]=true; // delete variable, no need to reset
	}else{
		printf("one or both inputs were not variables");
	}
}

void printV(int location){ // print ASCII value
	movePointer(location);
	printf(".");
}

void printC(char c){ // print a character (any ASCII) character in ' '
	int temp = newVariable();
	
	addN(temp, c);
	movePointer(temp);
	printf(".");
	resetVariable(temp);
	
	available[temp]=true;
}

int main(){
	setup();
	// Your code starts here
	printC('H');
	printC('i');
	int a = newVariable(3);
	int b = newVariable(2);
	mulV(a, b);
	addN(b, 48);
	printV(b);
	// and ends here
	
	return 0;
}
