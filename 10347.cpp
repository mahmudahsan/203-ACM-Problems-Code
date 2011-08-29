/* Problem: Medians UVa 10347
   Programmer: Md. Mahmud Ahsan
   Description: Geometry
   Compiled: Visual C++ 7.0
   Date: 26-10-05
*/
/*
  if m1,m2,m3 are medians
  s = 0.5 * (m1+m2+m3)
  area = (4/3) * sqrt(s * (s-m1) * (s-m2) * (s-m3))
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	double m1, m2, m3, s, area;

	while (cin >> m1 >> m2 >> m3){
		s = 0.5 * (m1+m2+m3);
		area = (4.0 / 3.0) * sqrt ( s * (s-m1) * (s-m2) * (s-m3));

		if (area > 0.0)
			printf("%.3lf\n", area);
		else
			printf("-1.000\n");
	}

	return 0;
}