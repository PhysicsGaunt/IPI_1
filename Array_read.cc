#include "fcpp.hh"


int array_output
int array_sort
int return_break


int input_case (int input, int array) {
	
	switch (input) {
		case -1: cout<<"Programm terminiert!"; return -1; break;
		case 0: array_output(array); return 0; break;
		default: return input; break;
	}
} 


int main () {
	
	int array[10];
	int i = 0;
	int input;
	
	while (i<10) {
		cin>>input;
		array [i] = input_case (input, array);
		array_sort(array);
		
		if (array[i]== -1) {i=10;};
		if (array[i]!=0) { i++;};
	};
	
	return return_break;
}
