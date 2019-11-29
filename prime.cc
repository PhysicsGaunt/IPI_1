#include <iosteam>
#include <stdlib.h>
#include <math.h>

struct primes {
	int prime;
	int position=0;
	int prime[2][500];
};

int next_divident (int progress, int position) {
	do {
		if (prime%progress==0) {primes[1][position]=1; return progress;}
		else {prime++;}
	} while(progress<=sqrt(prime));
	return 0;
}

void potenz (int progress, int position) {
	int count=2;
	do {
		if (prime%(count*progress)==0) {primes[1][position-1]++;}
		else {count=prime;}
		count++;
	} while (count<=sqrt(prime))
}

int main (int argc, char** argv) {
	prime p;
	p.prime = argv[0];
	int progress=2, position=0;
	
	do {
		progress=next_divident(progress,position);
		if (progress!=0) {
			potenz(progress, position);
		}
		progress++; position++;
			
	} while(progress<=sqrt(prime));
	 	
