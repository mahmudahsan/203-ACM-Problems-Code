/* Problem:  Find the Telephone UVa 10921
   Programmer: Md. Mahmud Ahsan
   Description: Simulation
   Compiled: Visual C++ 7.0
   Date: 17-02-06
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	int a[100], i, len;
	string str;

	a['1'] = 1; a['0'] = 0; 
	a['A'] = a['B'] = a['C'] = 2;
	a['D'] = a['E'] = a['F'] = 3;
	a['G'] = a['H'] = a['I'] = 4;
	a['J'] = a['K'] = a['L'] = 5;
	a['M'] = a['N'] = a['O'] = 6;
	a['P'] = a['Q'] = a['R'] = a['S'] = 7;
	a['T'] = a['U'] = a['V'] = 8;
	a['W'] = a['X'] = a['Y'] = a['Z'] = 9;

	while (cin >> str){
		len = str.size();
		for (i = 0; i < len; ++i){
			if (str[i] == '-')
				cout << "-";
			else 
				cout << a[str[i]];
		}
		cout << endl;
	}

	return 0;
}
