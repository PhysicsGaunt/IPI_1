#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

/* Da keine Arrays als Argumente oder returns ist alles in der main function.
   input: Werte des Arrays bzws. 0 (Array ausgeben), -1 (Programm terminieren);
   return 0*/ 

int main () {
	
	int array[10];			// Array wird definiert
	int i = 0;
	int input;
	
	for (int k=0; k<=9; k++) array[k]=0;		// Array wird in jeder Stelle auf 0 gesetzt
	
	do {												// do...while schleife sodass bei Fehlern oder Eingabe "-1" terminiert werden kann
	cout<<"Geben Sie die "<<i+1<<". Zahl ein: ";
	cin>>input;												// Eingabe Wert fuer Array
	
		if (input<-1) {cout<<"Nur positive Zahlen erlaubt!"; i=-100;}	// Abfangen negativer Eingaben außer "-1"
		
		else if (input==-1) {cout<<"Programm terminiert!"; i=-100;}		// "-1" terminiert
		
		else if (input==0) {											// "0" gibt aktuelles Array aus
				cout<<"Array: [ ";
				for (int i=0; i<10; i++) {
					cout<<array[i]<<" ";
				}
				cout<<"]"<<endl;
				}
				
		else  if (i<10) {array[i]=input; i++;}							// Normale Eingabe ausser bei vollem Array
			else {cout<<"ARRAY IST VOLL!\n"; i=-100; }
	
		if (i==10) {cout<<"Array ist voll!\n";}							// Letzte moegliche Eingabe


		for (int m=0; m<=i; m++) {										// bubble sort
			for (int l=0; l<i-m-1; l++) {
				if (array[l]>array[l+1]) {int zwischenspeicher=array[l]; array[l]=array[l+1]; array[l+1]=zwischenspeicher;}
			}	
		}
	} while(i!=-100);
	
	return 0;
}

