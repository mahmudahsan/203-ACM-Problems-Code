/* Problem: Pizza Cutting  UVa 10079
   Programmer: Md. Mahmud Ahsan
   Compiled: Modifed version in Turbo C++ 
   Date: 04-10-04
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long long int input, result;

	while (cin >> input){
		if (input < 0) break;
		result = ((input * (input + 1))/2) + 1;
		cout <<  result << endl;
	}
	return 0;
}
