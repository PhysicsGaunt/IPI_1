#include <iostream>

using namespace std;

void array_output (int array[10]) {
	cout<<"Array: [ ";
	for (int i=0; i<10; i++) {
		cout<<array[i]<<" ";
	}
	cout<<"]"<<endl;
}


int main () {
	
	int array[10];
	int i = 0;
	int input;
	
	for (int i: array) array[i]=0;
	
	do {
	cout<<"Geben Sie die "<<i+1<<". Zahl ein: ";
	cin>>input;
	
		if (i<10) {
			if (input<-1) {cout<<"Nur positive Zahlen erlaubt!"; i=-100;}
			else if (input==-1) {cout<<"Programm terminiert!"; i=-100;}
			else if (input==0) {array_output(array);}
			else {array[i]=input; i++;}
		}
		else {cout<<"ARRAY IST VOLL!"; i=-100;}
		if (i==10) {cout<<"Array ist voll!\n";}


		for (int m=0; m<=i; m++) {
			for (int k=0; k<=i-m; k++) {
				if (array[k]>array[k+1]) {int zwischenspeicher=array[k]; array[k]=array[k+1]; array[k+1]=zwischenspeicher;}
			}	
		}
	} while(i!=-100);
	
	return 0;
}
