/* Problem: Simple Division UVa 10407
   Programmer: Md. Mahmud Ahsan
   Description: GCD, for divisor, subtract smallest number from all other then gcd
   Compiled: Visual C++ 7.0
   Date: 03-06-05
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
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
	long small, next, temp;

	while (cin >> small){
		if (small == 0) break;
		cin >> next;
		temp = abs(next - small);
             	while (cin >> next){
			if (next == 0) break;
			temp = gcd(temp, abs(next-small));
		}
		cout << temp << endl;
	}
	return 0;
}