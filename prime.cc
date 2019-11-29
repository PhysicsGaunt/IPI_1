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
	for (teiler=2; teiler<=sqrt(zahl)+1; teiler++)
		while (zahl%teiler==0) {
			if(erstes==true)	cout << teiler;
			else				cout << "*" << teiler;
			erstes=false;
			zahl/=teiler;
		}
		return 0;
}
