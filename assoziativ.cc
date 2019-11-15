#include "fcpp.hh"

using namespace std;

/* Berechnet (a+b)+c : Bekommt a,c,b
 * Berechnet zuerst das Zwischenergebniss a+b
 * Returned dann Zwischenergebniss+c*/
 
float erste_klammer (float a, float b, float c) {

	float zwischenergebniss;
	zwischenergebniss=a+b;
	return (zwischenergebniss+c);
}

/* Berechnet a+(b+c) : Bekommt a,c,b
 * Berechnet zuerst das Zwischenergebniss b+c
 * Returned dann a+Zwischenergebniss*/
 
float zweite_klammer (float a, float b, float c) {

	float zwischenergebniss;
	zwischenergebniss=b+c;
	return (a+zwischenergebniss);
}

/* Ruft erste_klammer und zweite_klammer mit den Werten auf
 * Gibt die Rechnungen mit verschiedener Reihenfolge aus
 * Returned 0*/
 
int main () {
	
	for (int i=1; i<=14; i++) {		/* Startet bei 1 um besser zu sehen, was bei verschiedenen Potenzen passiert. */
		float a=pow(10,i);
		float b=-pow(10,i);
		float c=pow(10,-i);
		cout.precision(8);
		cout<<erste_klammer(a,b,c)<<"					"<<zweite_klammer(a,b,c)<<endl;
	}
	return 0;
}
