#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

/* function deck_check: kontrolliert ob Karten in ursruenglicher Reihenfolge;
	input deck: aktualle Kartenposition, n: Kartenanzahl
	return true falls alle urspruengliche Reihenfolge sonst false*/
	
bool deck_check (int deck[], int n) {				
	
	for (int k=0; k<n; k++) {
		if (deck[k]!=k) { return false; }
	} 
	
	return true;
}

/*function main: fuehrt den Algorithmus zum perfect suffle fuer n Karten aus und gibt das Ergebniss aus.
	input: #Karten n im Code, da Arrays nicht dynamischen Platz reservieren duerfen
	output: return 0; Anzahl Mischen zur urspruenglichen Reihenfolge als cout */
int main () {
	
	int n=200;							// n: Kartenanzahl: muss gerade sein
	int deck[n];
	int deck_1[n/2];					// erste haelfte der Karten
	int deck_2[n/2];					// zweite haelfte der Karten
	int iterations_in=0;
	int iterations_out=0;					// Anzahl Vertauschungen
	int position_hand_1=0, position_hand_2=0;		// Zeigt auf Positionen in den Kartenhaelften
	
	for (int i=0; i<n; i++) { deck[i]=i; }				// Deck definiert als (0,...,n-1)
	

	do {						// Perfect shuffle in
		position_hand_1=0; position_hand_2=0; // reset hand position
		
		for (int k=0; k<n/2; k++) { deck_1[k]=deck[k]; }					// Aufteilen der Karten
		for (int k=0; k<n/2; k++) { deck_2[k]=deck[k+n/2]; }
		
		for (int k=0; k<n; k++) {
			if (k%2==0) { deck[k]=deck_1[position_hand_1]; position_hand_1++;}  // Karten neu "zusammenshufflen"
			else { deck[k]=deck_2[position_hand_2]; position_hand_2++;}
		}
			
		iterations_in++;
			
	} while (deck_check(deck, n)!=true);									// ueberpfuefung urspruengliche reihenfolge


								// perfect shuffle out
	do {
		position_hand_1=0; position_hand_2=0;	//reset hand position
		
		for (int k=0; k<n/2; k++) { deck_1[k]=deck[k]; }					// Aufteilen der Karten
		for (int k=0; k<n/2; k++) { deck_2[k]=deck[k+n/2]; }
		
		for (int k=0; k<n; k++) {
			if (k%2==0) { deck[k]=deck_2[position_hand_2]; position_hand_2++;}	// Karten neu "zusammenshufflen"
			else { deck[k]=deck_1[position_hand_1]; position_hand_1++;}
		}
			
		iterations_out++;
		
	} while (deck_check(deck, n)!=true);								// ueberpfuefung urspruengliche reihenfolge

	
	cout<<"\nNach "<<iterations_in<<" mal mischen sind die Karten wieder identisch zum Anfang mit perfect-shuffle-in.";
	cout<<"\nNach "<<iterations_out<<" mal mischen sind die karten wieder identisch zum Anfang mit perfect-shuffle-out.";
	return 0;
}
