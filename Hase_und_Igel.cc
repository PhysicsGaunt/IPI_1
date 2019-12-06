#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;


struct ListElem {

	ListElem* next;
};

struct List {

	int count;
	ListElem* first;
};


void insert_in_list (List* list, ListElem* ins) {

	ins->next=list->first;
	list->first=ins;
	list->count++;
}

ListElem* letztes_element (List* zyklus) {
	
	ListElem* i=zyklus->first;
	while (i->next!=0) {i=i->next;}
	i->next=zyklus->first;	
}


void erzeuge_schleife (int laenge, List* zyklus) {
	
	if(laenge==0) {return;}
	
	for (int i=0; i<laenge; i++) {
		
		ListElem* ins = new ListElem;
		insert_in_list (zyklus, ins);
	}
	
	letztes_element(zyklus);
}

void erzeuge_liste (int laenge, List* linear, List* zyklus) {
	
	if (laenge==0) {linear->first=zyklus->first; return;}
	
	for (int i=0; i<laenge; i++) {
		
		ListElem* ins = new ListElem;		
		insert_in_list (linear, ins);
		
		if(i==0) {ins->next=zyklus->first;}
	}
}

void print (List* list) {
	for (ListElem* i=list->first; i!=0; i=i->next) cout<<i<<"\n";
}

void hase_und_igel (List* liste, List* zyklus) {
	
	int schritte=1, erstes_treffen, zweites_treffen;	
	ListElem* igel = liste->first;
	ListElem* hase = liste->first;

	while (true) {
		
		igel=igel->next;
		hase=hase->next->next;
		if (igel==hase) {erstes_treffen=schritte; cout<<"Erstes Treffen nach "<<schritte<<" Schritten!\n"; break;}
		schritte++;
	}
	
	while (true) {
		
		igel=igel->next;
		hase=hase->next->next;
		if (igel==hase) {zweites_treffen=schritte; cout<<"Zweites Treffen nach "<<schritte<<" Schritten!\n"; break;}
		schritte++;
	}
	
	cout<<"Anzahl der Schleifenelemente: "<<fabs(zweites_treffen-erstes_treffen)+1;
		
}



int main () {
	
	int schleifenelemente, lineare_elemente;
	
	cout<<"Schleifenelemente: "; cin>>schleifenelemente;
	cout<<"Lineare Elemente: ";  cin>>lineare_elemente;
	
	List* zyklus = new List;
	zyklus->first=0;
	erzeuge_schleife (schleifenelemente, zyklus);
	
	List* linear = new List;
	linear->first=0;
	erzeuge_liste(lineare_elemente, linear, zyklus);
	
	//print (linear);
	hase_und_igel (linear, zyklus);
	return 0;
}
