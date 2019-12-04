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
	for (teiler=2; teiler<=sqrt(zahl)+1; teiler++)				// Alle Teiler
		while (zahl%teiler==0) {					// immer noch teilbar
			if(erstes==true)	cout << teiler;			// Ausgabe
			else			cout << "*" << teiler;	
			erstes=false;
			zahl/=teiler;						// Primzahl aus der Zahl herausnehmen
		}
	if (erstes==true) cout<<zahl;						// Falls Primzahl
	return 0;
}
