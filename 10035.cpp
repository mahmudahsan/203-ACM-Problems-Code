/* Problem: Primary Arithmetic UVa 10035 PC 110501 
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
*/

#include <iostream>
using namespace std;

int main(){
	long int a, b, c , _a, _b, result, carry;


	while (cin >> a >> b){
		if ( a == 0 && b == 0) break;
		carry = c = 0;
		while (a != 0 || b != 0){
			_a = a % 10;
			a = a / 10;
			_b = b % 10;
			b = b / 10;

			result = _a + _b + c;
			if (result >= 10){
				c=1;
				carry += 1;
			}
			else
				c=0;
		}
		
		if (carry == 0){
			cout << "No carry operation." << endl;
		}
		else if (carry == 1){
			cout << carry << " carry operation." << endl;
		}
		else if (carry > 1){
			cout << carry << " carry operations." << endl;
		}
	}

	return 0;
}