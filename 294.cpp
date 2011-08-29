
/* Problem: Divisors UVa 294
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 15-03-05
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, i; // number of inputlines
	long a, b, tempA, tempB;
	long maxDivisor, maxNumber; // final maximum divisor and number counts
	long sqRoot;
	long mD, quotient; // temporary maximum Divisor count

	long num, j; // use in loop
	cin >> n;
	for (i = 0; i < n; i++){
		maxDivisor = maxNumber = 0;
		cin >> a >> b;
		tempA = a;
		tempB = b;

		// special case
		if (a == 0 && b == 1){
			cout << "Between " << tempA << " and " << tempB << ", " << 1 
			<< " has a maximum of " << 1 << " divisors." << endl;
			continue;
		}
		else if (a == 0 && b != 0 && b != 1){
			a = 2;
		}

		for (num = a; num <= b; ++num){
			mD = 0;
			quotient = 0;
			sqRoot = sqrt( (double) num);
			for (j = 1; j <= sqRoot; ++j){
				if (num % j == 0){
					++mD;
					quotient = num / j;
					if (quotient > sqRoot)
						++mD;
				}
			}

			if (mD > maxDivisor){
				maxDivisor = mD;
				maxNumber = num;
			}
		}
		cout << "Between " << tempA << " and " << tempB << ", " << maxNumber 
			<< " has a maximum of " << maxDivisor << " divisors." << endl;

	}

	return 0;
}