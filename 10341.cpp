/* Problem: Solve It UVa 10341
   Programmer: Md. Mahmud Ahsan
   Description: Bisection Method
   Compiled: Visual Studio .Net
   Date: 24-12-05
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const long double ERROR = 1e-14;

//global
long double root, x0, x1, x2,f0, f1, f2;
long double p, q, r, s, t, u;

long double func(long double x){
	// p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u = 0
	double temp;
	temp = (p * exp(-x) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u);
	return temp;
}

long double bisection(){
	long double x1 = 1.0;
	long double x2 = 0.0;

	f1 = func(x1);
	f2 = func(x2);

	if (fabs(f1) < ERROR)
		return x1;
	if (fabs(f2) < ERROR)
		return x2;

	if (f1 * f2 > 0.0)
		return -1;

	while (true){
		x0 = (x1 + x2) / 2.0;
		f0 = func(x0);

		if (f1 * f0 < 0.0)
			x2 = x0;
		else{
			x1 = x0;
			f1 = f0;
		}
		if (fabs( (x2 - x1) / x2) < ERROR){
			root = ( x1 + x2) / 2.0;
			return root;
		}
	}
	return -1;
}

int main(){
	long double temp;
	while (cin >> p >> q >> r >> s >> t >> u){
		temp = bisection();
		if (temp < 0)
			cout << "No solution" << endl;
		else
			printf("%.4Lf\n", temp);
	}
	return 0;
}