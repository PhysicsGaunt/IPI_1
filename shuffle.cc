#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

enum shuffle_mode {IN=1, OUT=2}; 		// definiere shuffle_mode als enum fuer Mischart

istream& operator>> (istream& in, shuffle_mode& shuffle) {		// overload Eingabeoperator, damit ein cin eines strings zu einer shuffle_mode transformiert wird bei cin>>shuffle
    std::string token;
    in >> token;
    if ( token == "IN" || token == "1" ){shuffle=IN;}
    else if ( token == "OUT" || token == "2" ){shuffle=OUT;}
    else { cout<<"Nur 'IN' oder 'OUT' sind akzeptierte Eingaben!" ;}
    return in;
}

/* function deck_check: kontrolliert ob Karten in ursruenglicher Reihenfolge;
	input deck: aktualle Kartenposition, n: Kartenanzahl
	return true falls alle urspruengliche Reihenfolge sonst false*/
	
bool deck_check (int deck[], int n) {				
	
	for (int k=0; k<n; k++) {
		if (deck[k]!=k) { return false; }
	} 
	
	return true;
}

/* function main: Deklarierungen und "mischen" der Karten
	input: shuffle: Mischmethode (IN / OUT) 
	return 0*/

int main () {
	
	
	shuffle_mode shuffle;     
	
	int n=200;							// n: Kartenanzahl: muss gerade sein
	int deck[n];
	int deck_1[n/2];					// erste haelfte der Karten
	int deck_2[n/2];					// zweite haelfte der Karten
	int iterations=0;					// Anzahl Vertauschungen
	int position_hand_1=0, position_hand_2=0;		// Zeigt auf Positionen in den Kartenhaelften
	
	for (int i=0; i<n; i++) { deck[i]=i; }				// Deck definiert als (0,...,n-1)
	
	cout<<"Shuffle mode? (IN or OUT): ";
	cin>>shuffle;
	
	if (shuffle == IN) {             // Perfect-in-shuffle
		do {
			position_hand_1=0; position_hand_2=0; // reset hand position
			
			for (int k=0; k<n/2; k++) { deck_1[k]=deck[k]; }					// Aufteilen der Karten
			for (int k=0; k<n/2; k++) { deck_2[k]=deck[k+n/2]; }
			
			for (int k=0; k<n; k++) {
				if (k%2==0) { deck[k]=deck_1[position_hand_1]; position_hand_1++;}  // Karten neu "zusammenshufflen"
				else { deck[k]=deck_2[position_hand_2]; position_hand_2++;}
			}
			
			iterations++;
			
		} while (deck_check(deck, n)!=true);									// ueberpfuefung urspruengliche reihenfolge
	}
	
	if (shuffle == OUT) {			// Perfect-out-shuffle
		do {
			position_hand_1=0; position_hand_2=0;	//reset hand position
			
			for (int k=0; k<n/2; k++) { deck_1[k]=deck[k]; }					// Aufteilen der Karten
			for (int k=0; k<n/2; k++) { deck_2[k]=deck[k+n/2]; }
			
			for (int k=0; k<n; k++) {
				if (k%2==0) { deck[k]=deck_2[position_hand_2]; position_hand_2++;}	// Karten neu "zusammenshufflen"
				else { deck[k]=deck_1[position_hand_1]; position_hand_1++;}
			}
				
			iterations++;
			
		} while (deck_check(deck, n)!=true);								// ueberpfuefung urspruengliche reihenfolge
	}
	
	cout<<"\nNach "<<iterations<<" mal mischen sind die Karten wieder identisch zum Anfang.";
	return 0;
}
