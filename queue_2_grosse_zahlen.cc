#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>

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
	
	for (int i=0; i<100000; i++) {
		
//	IntListElem* neu = new IntListElem;  // ENTKLAMMERN ZUM EINFÜGEN
//	neu->value=rand();
//	insert_in_list (queue, neu);
	
	
//	int integer=extract_from_list(queue); // ENTKLAMMERN ZUM AUSGEBEN

	}
	return 0;
}
