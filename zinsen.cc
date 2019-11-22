#include "fcpp.hh"

using namespace std;

/* Berechnet Zinsen in float
 * Bekommt Zinssatz z (float) und Zinsabrechnungen n (int)
 * Returned effektive Zinsen (float)*/
 
float zins_float (float z, int n) {
	
	return pow((1+z/n),n)-1;
}

/* Berechnet Zinsen in double
 * Bekommt Zinssatz z (float) und Zinsabrechnungen n (int)
 * Returned effektive Zinsen (double)*/
 
double zins_double (double z, int n) {
	
	return pow((1+z/n),n)-1;
}

/* Stellt Ergebnisse dar (siehe Aufgabe)*/
 
void Output (float z, int n) {

	cout.precision(5);
	cout<<"n: "<<n<<endl;	// Abrechnungen n
	cout<<"Zins Float: "<<zins_float(z,n)<<endl;	//Zins in Float
	cout<<"Abstand zu Float: "<<fabs((exp(z)-1)-zins_float(z,n))<<endl;	//Abstand zu (exp(z)-1) von float
	cout<<"Zins Double: "<<zins_double(z,n)<<endl;	//Zins in Double
	cout<<"Abstand zu Double: "<<fabs((exp(z)-1)-zins_double(z,n))<<"\n \n";	//Abstand zu (exp(z)-1) von double
}

/* Ruft die Outpunkt-Funktion mit den Werten fuer n auf
 * Returned 0*/
 
int main () {
	
	float z=0.06;
	
	Output(z,1);
	Output(z,4);
	Output(z,12);
	Output(z,365);
	Output(z,365*24);
	Output(z,365*24*60);
	Output(z,365*24*60*2);
	Output(z,365*24*60*60);
	
	return 0;
}
