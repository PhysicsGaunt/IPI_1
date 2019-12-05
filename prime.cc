#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
	int zahl, teiler;
	bool erstes=true;
	
	cout<<"Zahl: ";
	cin>>zahl;
	cout<<"Primzahlzerlegung von "<<zahl<<" : ";
	for (teiler=2; teiler<=sqrt(zahl); teiler++) {				// Alle Teiler
		while (zahl%teiler==0) {					// immer noch teilbar
			if(erstes==true)	cout << teiler;			// Ausgabe
			else			cout << "*" << teiler;	
			erstes=false;
			zahl/=teiler;						// Primzahl aus der Zahl herausnehmen
		}
	}
	if (zahl!=1) cout<<"*"<<zahl;
	cout<<"\n\n\n\n";
	return 0;
}
