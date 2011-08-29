/* Problem: Summation of Polynomials UVa 10302
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 23-03-05
*/ 
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long double array[50001];

int main(){
	long double result;
	long double input;

	int i, k = 1;
	for (i = 0; i < 50001; i++){
		array[i] = pow(k, 3);
		++k;
	}


	while (cin >> input){
		result = 0;
		for (i = 0; i < input; ++i)
			result = result + array[i];
		printf("%.0LF\n", result);
	}
	return 0;
}