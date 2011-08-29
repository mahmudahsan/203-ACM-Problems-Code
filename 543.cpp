/* Problem: Goldbach's Conjecture UVa 543
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 01-12-04
*/
#include <iostream>
#include <cmath>
using namespace std;

//--------------------------
const int limit = 1000002;
long primes[1000002]; // contains prime numbers
//--------------------------

void initPrimes(); // using sieve medhod
//==========================
int main(){
	long input;
	int i;

	initPrimes();
	while (cin >> input){
		if (input == 0) break;
		
		// applying goldbach's conjecture
		for (i = 2; i <= input; i++){
			if (primes[i] && primes[input - i]){
				cout << input << " = " << i << " + " << input - i << endl;
				break;
			}
			if (i == input)
					cout << "Goldbach's conjecture is wrong." << endl;
		}

	}
	return 0;
}

void initPrimes(){
	// prime factors using sieve method
	int i, j;

	for (i = 0; i <= limit; i++)
		primes[i] = 1;

	primes[0] = primes[1] = 0;

	for (i = 2; i < limit; i++){
		for (j = i + i; j < limit; j += i){
			primes[j] = 0;
		}
	}
}