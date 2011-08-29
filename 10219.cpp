/* Problem: Find the ways! UVa 10219
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 24-12-04
*/

#include <iostream>
#include <cmath>
using namespace std;

typedef double dbl;

dbl nCr(long n, long r);

int main(){
	dbl n, r;
	double result;
	cout.precision(0);

	while (cin >> n >> r && !cin.eof()){
		if (!n && !r) break;

		result = nCr(n, r);
		cout << result << endl;
	}
	return 0;
}

dbl nCr(long n, long r){
	dbl result = 0;

	if (n - r < r)
		r = n - r;

	for (long i = 1; i <= r; i++)
		result = result + (log10(n--) - log10(i));
	
	return floor(result) + 1;
}