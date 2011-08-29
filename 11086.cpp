/* Problem: Composite Prime UVa 11086
   Programmer: Md. Mahmud Ahsan
   Description: Prime
   Compiled: Visual C++ 7.0
   Date: 10-09-06
*/
#include <iostream>
#include <string>
using namespace std;

const int MX = 1548578;

char seive[MX];

void genSeive(){
	seive[0] = seive[1] = 0;

	for (int i = 2; i * i < MX; ++i){
		if (!seive[i])
			for (int j = i * i; j < MX; j+=i)
				seive[j] = 1;
	}

	for (int i = 4; i < MX; ++i){
		if (seive[i])
			for (int j = i * 2; j < MX; j+=i)
				seive[j] = 0;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	genSeive();
	int n, i, temp, counter;

	while (cin >> n){
		counter = 0;
		for (i = 0; i < n; ++i){
			cin >> temp;
			if (seive[temp])
				++counter;
		}
		cout << counter << endl;
	}

	return 0;
}
