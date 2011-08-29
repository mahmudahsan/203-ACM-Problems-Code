/* Problem:  Perfect Cubes  UVa 386
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 23-03-05
*/ 

#include <iostream>
using namespace std;

int main(){
	long a, b, c, d;

	for (a = 6; a <= 200; ++a){
		for (b = 2; b < a; ++b){
			for (c = b; c < a; ++c){
				for (d = c; d < a; ++d){
					if (a*a*a == (b*b*b) + (c*c*c) + (d*d*d))
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
				}
			}
		}
	}


	return 0;
}