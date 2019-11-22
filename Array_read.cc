#include "fcpp.hh"


int array_output (int[] array) {
	cout<<"Array: [ ";
	for (int i=0; i<10; i++) {
		cout<<array[i]<<" ";
	};
	cout<<"]"<<endl;
}


int return_break () {
	int end;
	cout<<"Das Array ist voll!"<<endl;
	cin>>end;
	if (end!=-1) {cout "ARRAY IST VOLL"; return -1;}
	return 0;
}


int main () {
	
	int array[10];
	int i = 0;
	int input;
	
	while (i<10) {
		cout<<"Geben Sie eine Zahl ein: ";
		cin>>input;
		
		if (input<-1) {cout<<"Nur positive Zahlen erlaubt!"; i=100;};
			else if (input==-1) {cout<<"Programm terminiert!"; i=100;};
			else if (input==0) {array_output(array);};
			else {array[i]=input; i++;};
	};
	
	for (int m=i; i>=0, m--) {
		for (int k=0; k<=m; k++) {
			if (array[k]<array[k+1]) {int zwischenspeicher=array[k]; array[k]=array[k+1]; array[k+1]=zwischenspeicher;}
		}
	}
	
	return return_break;
}
