#include "fcpp.hh"
#include <iostream>

float determinante (float a, float b, float c, float d) {
	
	return print (a*d-b*c);
}

int main(int argc, char** argv) {
	
	float a = readarg_float(argc, argv, 1);
	float b = readarg_float(argc, argv, 2);
	float c = readarg_float(a rgc, argv, 3);
	float d = readarg_float(argc, argv, 4);
	
	determinante(a, b, c, d);
	
	return 0;
}	
