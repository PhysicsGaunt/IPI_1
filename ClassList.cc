#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;


struct IntListElem {
	IntListElem* next;
	int value;
};


class IntList {
	
	public:
		// Konstruktor, erzeuge eine leere Liste
		IntList();
		
		// Copy-Konstuktor
		IntList(IntList &list);
		
		// Destruktor, loescht gesamten Listeninhalt
		~IntList();
		
		// Gibt Anzahl der Elemente zurueck
		int getCount();
		
		// Gibt zurueck, ob die Liste leer ist
		bool isEmpty();
		
		// Gibt die Liste aus
		void print();
		
		// Fuegt die Zahl 'element' an der (beliebigen) Position 'position' ein
		void insert (int element, int position);
		
		// Insert ohne position traegt es ans ende der Liste ein
		void insert (int element);
		
		// Loescht das Element an der Position 'position
		void remove (int position);
		
		// Gibt den Wert des ELements an der Position 'position' zurueck
		int getElement(int position);
		
		// Gibt Zeiger aus Element an der Position 'position' zurueck
		IntListElem* ElemAtPos(int position);
		
		// Zuweisungsoperator '='
		IntList &operator=(IntList &list);

	private:
		int count;
		IntListElem* first;
};


IntList::IntList() {			// Konstruktor, setzt erstes Element auf 0 und count auf 0
	
	this->count=0;
	this->first=0;
}


IntList::IntList(IntList &list) {			// Copy-Konstruktor, wie konstruktor, aber falls mit nicht-leerem Feld iniziiert-> kopieren der elemente
	
	this->count=0;
	this->first=0;
	
	if (!list.isEmpty()) {					// Liste leer?
		
		for (int i=0; i<list.count; i++) {
			
			insert(list.getElement(i), i);
		}
	}
}


IntList& IntList::operator=(IntList &list) {			// Zuweisungsoperator
	
	if (&list!=this) {				// Gleiches Element?
		
		this->~IntList();
		this->count=0;
		this->first=0;
		if (!list.isEmpty()) {		// Liste leer?
			
			for (int i=0; i<list.count; i++) {
				
				insert(list.getElement(i), i);
			}	
		}
	}
	return *this;
}


IntList::~IntList() {				// Destruktor: loescht alle eintraege
	
	for (int i=0; i<=this->count; i++) {
		
		remove(0);
	}
}


int IntList::getCount() {			// returned Listenelementenanzahl

	return this->count;
}


bool IntList::isEmpty() {			// true=leer, false=nicht leer
	
	return (this->count==0) ? true : false;
}


void IntList::print() {
	
	if (!this->isEmpty()) {				// liste leer?
		
		IntListElem* pos=this->first;
		for (int i=0; i<count; i++) {
			
			cout<<pos->value<<endl;
			pos=pos->next;
		}
	cout<<"\n\n\n";
	}
	
	else {
		cout<<"Die Liste ist leer!\n";
	}
}

void IntList::insert(int element, int position) {

	if (position>this->count) { cout<<"Die Liste hat bisher nur "<<this->count<<" Elemente.\n"; return;}	// Fehler: Einfuegen an zu hoher Stelle (Ausesrhalb der liste)
	IntListElem* ListElem = new IntListElem;
	
	if (position==0) {					// Als erstes element einfuegen
		
		this->first=ListElem;
		ListElem->next=0;
		ListElem->value=element;
		this->count++;
	}
	
	else {							// Nicht erstes Element einfuegen
	
	IntListElem* ElementBefore = ElemAtPos(position-1);	
	IntListElem* NextElement = ElementBefore->next;
	ElementBefore->next=ListElem;
	ListElem->next=NextElement;
	ListElem->value=element;
	this->count++;
	}
}


void IntList::insert(int element) {				// Insert ohne position -> element als letztes an Liste gehaengt

	int position=this->count;
	IntListElem* ListElem = new IntListElem;
	
	if (position==0) {					// Als erstes element einfuegen
		
		this->first=ListElem;
		ListElem->next=0;
		ListElem->value=element;
		this->count++;
	}
	
	else {							// Nicht erstes Element einfuegen
	
	IntListElem* ElementBefore = ElemAtPos(position-1);	
	IntListElem* NextElement = ElementBefore->next;
	ElementBefore->next=ListElem;
	ListElem->next=NextElement;
	ListElem->value=element;
	this->count++;
	}
}


void IntList::remove(int position) {
	
	if (position>=this->count) { cout<<"Die Liste hat bisher nur "<<this->count<<" Elemente.\n"; return;}	// Fehler: Entfernen nicht exetenter Elemente

	if (position==0) {					// entfernen erstes Element
			
		IntListElem* NextAfterRemove = this->first->next;
		delete this->first;
		this->first=NextAfterRemove;
		this->count--;
	}
	
	else {						// Entfernen nicht erstes element
		
		IntListElem* NextWillBeRemoved = ElemAtPos(position-1);
		IntListElem* NextAfterRemove = NextWillBeRemoved->next->next;
		delete NextWillBeRemoved->next;
		NextWillBeRemoved->next=NextAfterRemove;
		this->count--;
	}
}


int IntList::getElement(int position) {				// Wert an position 'position'
	
	return ElemAtPos(position)->value;
}


IntListElem* IntList::ElemAtPos(int position) {			// Zeiger auf position 'position'
	
	IntListElem* pos=this->first;
	for (int i=0; i<position; i++) { pos=pos->next; }
	return pos;
}


int main () {
	IntList list;
	list.insert(30);
	list.insert(20);
	list.insert(10);
	list.print();
	
	list.remove(2);
	list.print();
	
	list.insert(30, 2);
	list.print();
	
	list.insert(40, 3);
	list.print();
	
	IntList copy(list);
	copy.print();
	
	copy.remove(0);
	copy.print();
	list.print();
	
	copy = list;
	copy.print();
	
	return 0;
}
