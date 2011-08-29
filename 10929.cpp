/* Problem:  You can say 11 UVa 10929
   Programmer: Md. Mahmud Ahsan
   Description: Number Theory
   Compiled: Visual C++ 7.0
   Date: 17-02-06
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	string str;
	int i, result;
	bool alt;

	while (cin >> str){
		if (str == "0") break;
		result = 0;
		alt = false;
		for (i = 0; i < str.size(); ++i){
			if (!alt)
				result += str[i]-48;
			else
				result -= str[i]-48;
			alt = !alt;
		}
		if (result % 11 == 0)
			cout << str << " is a multiple of 11." << endl;
		else
			cout << str << " is not a multiple of 11." << endl;
	}

	return 0;
}
