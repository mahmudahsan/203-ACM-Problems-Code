/* Problem: Ecological Premium UVa 10300
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 20-10-04
*/

/* let a = area, b = animals, c = envirounment friendliness
the given condition
((a / b) * c ) * c, it can be expressed
= a * c
*/ 

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int test, farmer; 
	double a, b, c, result;
	int i, j;

	cin >> test;
	
	for (i = 0; i < test; i++){
		result = 0;
		cin >> farmer;
		
		for (j = 0; j < farmer; j++){
			cin >> a >> b >> c;
			result += a * c;
		}
		printf("%.0lf\n", result);
	}
	return 0;
}