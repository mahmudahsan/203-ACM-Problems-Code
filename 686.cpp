/* Problem: Goldbach's Conjecture (II)  UVa 686
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 01-12-04
*/

#include <iostream>
using  namespace std;

void initPrimes(long array[], long limit);
//===========================================
int main(){
	long input;
	long primes[32770];
	int i;
	int count;

	while (cin >> input){
		count = 0;
		if (input == 0) break;
	
		initPrimes(primes, input);
		
		for (i = 2; i <= input; i++){
			if (primes[i] && primes[input - i]){
				++count;
				primes[input - i] = 0;
			}
			if (i == input) break;
		}
		cout << count << endl;
	}

	return 0;
}

void initPrimes(long array[], long limit){
	int i, j;

	for (i = 0; i < limit; i++)
		array[i] = 1;

	array[0] = array[1] = 0;

	for (i = 2; i <= limit; i++){
		for (j = i + i; j <= limit; j += i)
			array[j] = 0;
	}
}