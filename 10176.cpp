/* Problem: Ocean Deep! Make it shallow!! UVa 10176
   Programmer: Md. Mahmud Ahsan
   Description:  Binary to decimal, Module
   Compiled: Visual C++ 7.0
   Date: 10-06-05
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	char str[20000];
	int i, len, number;
	char ch;

	while (cin >> ch){
		number = 0;
		number += ch - 48;
		while (cin >> ch){
			if (ch == '#') break;
			number = number << 1;//left shift multiplying by 2 each time
			number += ch - 48;
			number = number % 131071;
		}
	
		if (number == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}