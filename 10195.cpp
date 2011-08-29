/* Problem: The Knights Of The Round Table  UVa 10195
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 19-08-04
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double a, b, c;
	double s, r;

	while (cin >> a >> b >> c){
		// special case
		if (a == 0.0 || b == 0.0 || c == 0.0){
			// special case
			cout << "The radius of the round table is: 0.000" << endl;
			continue;
		}
		// law in geometry
		s = (a + b + c) / 2;
		r = ( sqrt(s * (s - a) * (s - b) * (s - c) ) ) / s;
		
		cout << setiosflags(ios :: fixed) << setprecision(3) << "The radius of the round table is: " << r << endl;
	}
	return 0;
}