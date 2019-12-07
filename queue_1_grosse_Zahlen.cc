#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct IntListElem {

	IntListElem* next;
	int value;
};

struct IntList {

	int count;
	IntListElem* first;
};

void insert_in_list (IntList* list, IntListElem* ins) {

	ins->next=list->first;
	list->first=ins;
	list->count++;
}

IntListElem* SLast_Elem (IntList* list) {

	int i=1;
	IntListElem* zaehler = list->first;
	while (i<list->count-1) {zaehler=zaehler->next; i++;}
	return zaehler;
}

int extract_from_list (IntList* list) {
	
	if (list->count==1) {
		int wert = list->first->value;
		list->first=0;
		list->count--;
		return wert;
	}
	
	
	IntListElem* vorletztesElement = SLast_Elem(list);	
	int wert=vorletztesElement->next->value;
	vorletztesElement->next = 0;
	list->count--;
	return wert;
}


int main() {

	IntList* queue = new IntList;
	queue->count=0;
	queue->first=0;

	for (int i=0; i<100000; i++) {

//	IntListElem* neu = new IntListElem;  // ENTKLAMMERN ZUM EINFÜGEN
//	neu->value=rand();
//	insert_in_list (queue, neu);
	
	
//	int integer=extract_from_list(queue); // ENTKLAMMERN ZUM AUSGEBEN
	}
	return 0;
}
