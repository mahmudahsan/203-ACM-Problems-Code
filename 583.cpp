/* Problem: Prime Factors UVa 583
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 30-11-04
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// this functions collect all the primes limit number = 2147483648
void initPrime(vector <int> &ob){
	int i, j;
	int array[46345];
	
	array[0] = array[1] = 0;
	for (i = 2; i < 46345; i++)
		array[i] = 1;

	for (i = 2; i < 46345; i++){
		for (j = i + i; j < 46345; j = j + i){
			array[j] = 0;
		}
	}

	for (i = 2; i < 46345; i++){
		if (array[i] != 0){
			ob.push_back(i);
		}
	}
}

int main(){
	vector <int> primes;
	initPrime(primes); // now primes contains all the primes
	long input;
	long i;
	bool flag, primeFlag; // for presentation purpose

	while (cin >> input){
		flag = primeFlag = false;
		if (input == 0) break;

		if (input == -1)
			cout << "-1 = -1" << endl;
		else if (input == 1)
			cout << "1 = 1" << endl;
		else if (input < 1){
			input = fabs(input);
			cout << "-" << input << " = -1 x ";

			// applying theory of prime factorization
			for (i = 0; i < primes.size(); ){
				if (primes[i] > input) break;
				if (input % primes[i] == 0){
					input = input / primes[i];
					if (flag) cout << " x ";
					cout << primes[i];
					flag = primeFlag = true;
					continue;
				}
				++i;
			}

			if (!flag) cout << input << endl;
			else
				cout << endl;
		}

		else if (input > 1){
			cout << input << " = ";

			for (i = 0; i < primes.size(); ){
				if (primes[i] > input) break;
				if (input % primes[i] == 0){
					input = input / primes[i];
					if (flag) cout << " x ";
					cout << primes[i];
					flag = primeFlag = true;
					continue;
				}
				++i;
			}

			if (!flag) cout << input << endl;
			else
				cout << endl;
		}

	}

	return 0;
}