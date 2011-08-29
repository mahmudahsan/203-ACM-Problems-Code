/* Problem: Perfection UVa 382
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 24-10-04
*/

#include <iostream.h>
#include <stdio.h>

typedef long int lint;

int main(){
	lint input;
	lint i, sum;

	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> input){
		if (input == 0){
			cout << "END OF OUTPUT" << endl;
			break;
		}
		sum = 0;
		for (i = 1; i <= input / 2; i++){
			if (input % i == 0)
				sum += i;
		}

		printf("%5ld  ", input);

		if (sum == input)
			cout << "PERFECT" << endl;
		else if (sum < input)
			cout << "DEFICIENT" << endl;
		else
			cout << "ABUNDANT" << endl;

	 }

	return 0;
}
