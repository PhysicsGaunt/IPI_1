#include "fcpp.hh"
#include <string.h> // fuer strlen, Laenge eines C-Strings

// Definieren Sie hier Ihren Stack und legen Sie eine Instanz als globale
// Variable an

typedef int element_type;

struct stack_struct{
	element_type stack[1000];
	int top = 0;
};

stack_struct s;
// Danach koennen Sie die Funktionen push() und pop() implementieren, die auf dieser
// globalen Variable operieren

void push(element_type e) {
	s.stack[s.top] = e;
	s.top++;
}

element_type pop() {
	s.top--;
	return s.stack[s.top];
} 


int main(int argc, char* argv[])
{
  // Setzen Sie hier auf einen leeren Stack

  // fange kein Kommandozeilenargument ab
  if(argc < 2)
  {
    print("Eingabe fÃ¼r den Taschenrechner erwartet!");
    return 1;
  }

  // arg enthaelt die als Eingabe von der Kommandozeile uebergebene Zeichenfolge
  char* arg = argv[1];
	
	bool zahl = false;
  // Schleife, die die Zeichen der Eingabe nacheinander ablaeuft
  // strlen gibt die Anzahl der Zeichen in der Zeichenkette
  for (int i = 0; i <= strlen(arg); i = i+1)
  {
    char zeichen = arg[i]; // aktuelles Zeichen
    // Beachten Sie: der Inhalt der Variable zeichen ist der ASCII-Code
    // des entsprechenden Zeichens. Dieser stimmt im Falle der Zeichen '0'..'9'
    // nicht mit der entsprechenden Ziffer Ã¼berein.
    
	if ((int)zeichen==0 || (int)zeichen==1 || (int)zeichen==2 || (int)zeichen==3 || (int)zeichen==4 || (int)zeichen==5 || (int)zeichen==6 || (int)zeichen==7 || (int)zeichen==8 || (int)zeichen==9) {
		
		if (zahl==true)		push(pop()*10+zeichen);
		else 				push(zeichen);
	}
	
	if (zeichen=="*") {
		push(pop()*pop());
	}
	
	if (zeichen=="/") {
		push(pop()/pop());
	}
	
	if (zeichen=="+") {
		push(pop()+pop());
	}
	
	if (zeichen=="-") {
		push(pop()-pop());
	}
	
    // Fuegen Sie hier Code ein, der das Zeichen verarbeitet, also Ziffern
    // zu Zahlen zusammenfÃ¼gt, Operatoren anwendet und andere Zeichen
    // ignoriert
  }
}
