/* Problem: Skew Binary UVa 575
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 05-08-04
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//prototype
long int skewBinary(char string[]);

//=====================================================
int main(){
	char string[500];
	long int result;

	while (cin >> string){
		if (string[0] == '0') break;
		
		result = skewBinary(string);
		cout << result << endl;
	}
	return 0;
}
//=====================================================

long int skewBinary(char string[]){
	long int result, temp;
	long int digit;
	int count;
	int i;
	
	result = 0;
	count = strlen(string);
	for (i = 0; string[i] != '\0'; i++){
		//convert a charcter of string to decimal form 
		digit = string[i] - 48;
		//as the problem has given the equation
		temp = digit * (pow(2, count) - 1);
		result += temp;
		--count;
	}

	if (result > 2147483647 || result < 0) return 2147483647;
	return result;
}