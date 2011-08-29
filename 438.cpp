/* Problem: The Circumference of the Circle  UVa 438
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 29-03-05
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define pi 3.141592653589793

int main(){
	double x1, x2, x3, y1, y2, y3;
	double a, b, c;
	double s, k, r, circum;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		a = sqrt( pow((x1-x2), 2) + pow((y1-y2), 2) );
		b = sqrt( pow((x2-x3), 2) + pow((y2-y3), 2) );
		c = sqrt( pow((x1-x3), 2) + pow((y1-y3), 2) );

		s = (a+b+c)/2;
		k = sqrt( s * (s-a) * (s-b) * (s-c));

		r = (a*b*c)/(4 * k);

		circum = 2 * pi * r;
		printf("%.2lf\n", (double) circum);
	}	

	return 0;
}