#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct IntListElem {

	IntListElem* next;
	IntListElem* before;
	int value;
};

struct IntList {

	int count;
	IntListElem* first;
	IntListElem* last;
};


IntListElem* SLast_Elem (IntList* list) {

	int i=1;
	IntListElem* zaehler = list->first;
	while (i<list->count-1) {zaehler=zaehler->next; i++;}
	return zaehler;
}

void insert_in_list (IntList* list, IntListElem* ins) {

	ins->next=list->first;
	ins->before=list->last;
	list->first=ins;
	list->count++;
}

int extract_from_list (IntList* list) {
	
	if (list->count==1) {
		int wert = list->first->value;
		list->first=0;
		list->last=0;
		list->count--;
		return wert;
	}
	
	
	IntListElem* vorletztesElement = SLast_Elem(list);	
	int wert=vorletztesElement->next->value;
	vorletztesElement->next = list->first;
	list->last=vorletztesElement;
	list->first->before=vorletztesElement;
	list->count--;
	return wert;
}


int main() {

	IntList* queue = new IntList;
	queue->count=0;
	queue->first=0;
	queue->last=0;
	
	int entscheidung;

	while (true) {
		
		if (queue->count!=0) {cout<<"Eingabe (1) oder Ausgabe (2) ? "; cin>>entscheidung;}
		if (queue->count==0) {entscheidung=1;}
		
		if (entscheidung==1) {
			int wert;
			cout<<"Eingabewert: "; cin>>wert;
			IntListElem* neu = new IntListElem;
			neu->value=wert;
			insert_in_list (queue, neu);
		}
		
		if (entscheidung==2) {
			cout<<extract_from_list(queue)<<"\n";
		}
	}
	return 0;
}
