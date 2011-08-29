/* Problem: To Carry or not to Carry  UVa 10469
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 09-08-04
*/

#include <iostream>
using namespace std;

/* Let p and q be propostions. The exclusive or XOR of p and q is the propostion
That is true when exactly one of p or q is true and false otherwise */

int main(){
	unsigned long int input1, input2, result;

	while (cin >> input1 >> input2){
		// See the logic diagram and found there showed to do XOR
		result = input1 ^ input2;
		cout << result << endl;
	}
	return 0;
}