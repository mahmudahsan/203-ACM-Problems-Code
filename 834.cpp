/* Problem: Continued Fraction UVa 834
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 11-09-04
*/


#include <iostream>
using namespace std;

typedef long int lint;

int main(){
	lint first, second, result, remain;
		
	while (cin >> first >> second){
		if (first == 0 && second == 0) break;

		result = first / second;
		remain = first % second;
		cout << "[" << result << ";";

		while (remain != 0){
			first = second;
			second = remain;

			result = first / second;
			remain = first % second;
			
			cout << result;
			if (remain > 0) cout << ",";
		}
	
		cout << "]" << endl;
	}

	return 0;
}