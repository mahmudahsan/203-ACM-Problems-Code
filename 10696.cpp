/* Problem: f91 UVa 10696
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 15-09-04
*/

#include <iostream>
#include <cmath>
using namespace std;

typedef long int lint;

// prototypes
lint f91(lint N);

//===========================================================
int main(){
	lint input;
	lint result;

	while (cin >> input){
		if (input == 0) break;
		result = f91(input);
		cout << "f91(" << input << ") = " << result << endl;
	}

	return 0;
}
//============================================================

lint f91(lint N){
	if (N <= 100)
		return f91(f91(N+11));
	else
		return N-10;
}