#include "fcpp.hh"

using namespace std;

/* Berechnet Determinante
 * Nimmt Matrixelemente a,b,c,d (float) 
 * Printed Determinante
 * Return unwichtig*/
 
float determinante (float a, float b, float c, float d) {
	
	return print (a*d-b*c);
}

/* Deklariert Variablen a,b,c,d (float) aus Input
 * Ruft "determinante" auf und ignoriert return
 * Return 0*/
 
int main(int argc, char** argv) {
	
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	float c = atof(argv[3]);
	float d = atof(argv[4]);
	
	determinante(a, b, c, d);
	
	return 0;
}	
