/* Problem: Number Chains UVa 263
   Programmer: Md. Mahmud Ahsan
   Description: Simulation
   Compiled: Visual C++ 7.0
   Date: 17-08-05
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

// compare function for decresing order
inline bool comp(char a, char b){
	return a > b;
}

vector <int> v; // collect all the new numbers

bool found(int n){
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == n)
			return true;
	return false;
}

int main(){
	char str[30];
	char strIncre[30], strDecre[30];
	int incre, decre, number;
	bool flag = false;

	while (cin >> str){
		if (str[0] == '0') break;

		if (flag) cout << endl; flag = true;
  		cout << "Original number was " << str << endl;
		do{
			strcpy(strIncre, str);
			strcpy(strDecre, str);
			sort(strIncre, strIncre+strlen(strIncre));
			sort(strDecre, strDecre+strlen(strDecre), comp);

			sscanf(strIncre, "%d", &incre);
			sscanf(strDecre, "%d", &decre);

			number = abs(decre - incre);
			cout << decre << " - " << incre << " = " << number << endl;
			
			if (found(number)) break;

			sprintf(str, "%d", number);
			v.push_back(number);
		}while (true);

		cout << "Chain length " << v.size()+1 << endl;
		v.clear(); // clear all the elements
	}
        cout << endl;
	return 0;
}