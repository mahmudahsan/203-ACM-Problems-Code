/* Problem: The primary problem. UVa 10948
   Programmer: Md. Mahmud Ahsan
   Description: Sorting + Output
   Compiled: Visual C++ 6.0
   Date: 18-02-06
*/
#include <iostream>
#include <string>
using namespace std;

const int MX = 1200000;

char seive[MX];

void genSeive(){
	seive[0] = seive[1] = 1;
	int i, j;

	for (i = 2; i * i <= MX; ++i){
		if (!seive[i])
			for (j = i * i; j < MX; j += i)
				seive[j] = 1;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);

	genSeive();
	int n, divN, total, i;
	bool found;

	while (cin >> n){
		if (n == 0) break;

		found = false;
		cout << n << ":" << endl;
		divN = n / 2;
		for (i = 1; i <= divN; ++i){
			if (seive[i] == 0 && seive[n-i] == 0){
				total = i + (n-i);
				if (total == n) {
					cout << i << "+" << (n-i) << endl;
					found = true;
					break;
				}
			}
		}
		if (!found)
			cout << "NO WAY!" << endl;
	}

	return 0;
}
