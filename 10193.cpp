/* Problem: All You Need Is Love UVa 10193
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC, GCD and Binary to decimal
   Compiled: Visual C++ 7.0
   Date: 03-06-05
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef unsigned long ulint;

ulint gcd(ulint x, ulint y){
	ulint r;
	while (y != 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main(){
    char strA[40], strB[40];
	ulint lenA, lenB, len, result;
	int n, i, j, cases = 0;
	cin >> n;
	for (i = 0; i < n; ++i){
		lenA = lenB = 0;
		cin >> strA >> strB;

		len = strlen(strA);
		for (j = 0; strA[j]; ++j)
			lenA += (strA[j] - 48) * pow (2, --len);
		len = strlen(strB);
		for (j = 0; j < strB[j]; ++j)
			lenB += (strB[j] - 48) * pow (2, --len);

		result = gcd(lenA, lenB);
		cout << "Pair #" << ++cases << ": ";
		
		if (result == 1)
			cout << "Love is not all you need!" << endl;
		else
			cout << "All you need is love!" << endl;
	}

	return 0;
}