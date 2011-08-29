/* Problem: Light More Light  UVa 10110
   Programmer: Md. Mahmud Ahsan
   Compiled: Linux GNU C++  Visual C++ 6.0
   Date: 04-09-04
*/ 


#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lint;

int main(){	
	lint input;
	lint _input;

	while (cin >> input){
		if (input == 0) 
			break;

		_input = sqrt(input);

		if (_input * _input == input)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		
	}
	return 0;
}