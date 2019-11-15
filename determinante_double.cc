
// Identisch zu determinante.cc nur mit double statt float

#include "fcpp.hh"

using namespace std;

/* Berechnet Determinante
 * Nimmt Matrixelemente a,b,c,d (double) 
 * Printed Determinante
 * Return unwichtig*/
 
float determinante (double a, double b, double c, double d) {
	
	return print (a*d-b*c);
}

/* Deklariert Variablen a,b,c,d (double) aus Input
 * Ruft "determinante" auf und ignoriert return
 * Return 0*/
 
int main(int argc, char** argv) {
	
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double c = atof(argv[3]);
	double d = atof(argv[4]);
	
	determinante(a, b, c, d);
	
	return 0;
}	
