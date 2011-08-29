/* Problem: Geometry Paradox UVa 10573
   Programmer: Md. Mahmud Ahsan
   Description: Geometry, if only t is given then r1 = r2, and there is no "impossible"
   Compiled: Visual C++ 7.0
   Date: 10-06-05
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define pi 2 * acos(0.0)

int main(){
	char item[100], temp[100];
	int a, b;
	double outerArea, cirBig, cir1, cir2;
	int test, t;
	cin >> test;
	// eat newline
	cin.getline(temp, sizeof(temp));
	for (t = 0; t < test; ++t){
		cin.getline(item, sizeof(item));
		a = b = 0;
		sscanf(item, "%d %d", &a, &b);
		if (a != 0 && b == 0){
			// if only t is given
			cirBig = pi * a/2 * a/2;
			cir1 = cir2 = pi * a/4 * a/4;
			outerArea = cirBig - (cir1+cir2);
		}
		else if (a == 0 && b != 0){
			// if only t is given
			a = b;
			cirBig = pi * a/2 * a/2;
			cir1 = cir2 = pi * a/4 * a/4;
			outerArea = cirBig - (cir1+cir2);
		}
		else{
			cir1 = pi * a * a;
			cir2 = pi * b * b;
			cirBig = pi * (a+b) * (a+b);
			outerArea = cirBig - (cir1+ cir2);
		}
		printf("%0.4lf\n", outerArea);
	}

	return 0;
}
