/* Problem: Problem C - 2 the 9s UVa 10922
   Programmer: Md. Mahmud Ahsan
   Description: Number Theory
   Compiled: Visual C++ 7.0
   Date: 19-08-06
*/
#include <iostream>
#include <string>
using namespace std;

const int MX = 1050;
char str[MX];
int n;

int getDegree(int number){
	int temp = 0;
	int digit;

	while (number != 0){
		digit = number % 10;
		number = number / 10;
		temp += digit;
	}
	return temp;
}


bool isMultiple(){
	int temp=0;
	int i;
	n = 1;

	for (i = 0; str[i]; ++i){
		temp += str[i]-48;
	}
	if (temp % 9 != 0) return false;

	while (temp != 9){
		++n;
		temp = getDegree(temp);
	}

	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);
	while (cin >> str){
		if (str[0] == '0') break;

		if (isMultiple())
			cout << str << " is a multiple of 9 and has 9-degree " << n << "."<<endl;
		else
			cout << str << " is not a multiple of 9." << endl;

	}

	return 0;
}
