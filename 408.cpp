/* Problem: Uniform Generator UVa 408
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 17-03-05
*/ 

/*description: By observing sample input/output we found that
when (gcd(x,y) == 1) => good choice, otherwise bad choice */

#include <iostream>
#include <cstdio>
using namespace std;

long gcd(long x, long y){
	long r;

	while (y != 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main(){
	long a, b, result;

	while (cin >> a >> b){
		result = gcd(a, b);

		if (result == 1)
			printf("%10ld%10ld     Good Choice\n", a, b);
		else
			printf("%10ld%10ld     Bad Choice\n", a, b);
		
	}

	return 0;
}

