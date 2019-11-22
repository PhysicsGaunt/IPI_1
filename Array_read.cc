#include "fcpp.hh"


int array_output (int[] array) {
	cout<<"Array: [ ";
	for (int i=0; i<10; i++) {
		cout<<array[i]<<" ";
	};
	cout<<"]"<<endl;
}


int main () {
	
	int array[10];
	int i = 0;
	int input;
	
	do {
	cout<<"Geben Sie die "<<i<<". Zahl ein: ";
	cin>>input;
	
		if (i<10) {
			if (input<-1) {cout<<"Nur positive Zahlen erlaubt!"; i=-100;};
				else if (input==-1) {cout<<"Programm terminiert!"; i=-100;};
				else if (input==0) {array_output(array);};
				else {array[i]=input; i++;};
		};
		else {cout<<"ARRAY IST VOLL!"; i=-100;};
		if (i==9) {cout<<"Array ist voll!";};


		for (int m=i; i>=0, m--) {
			for (int k=0; k<=m; k++) {
				if (array[k]<array[k+1]) {int zwischenspeicher=array[k]; array[k]=array[k+1]; array[k+1]=zwischenspeicher;}
			}	
		}
	} while (i!=-100);
	
	return 0;
}
