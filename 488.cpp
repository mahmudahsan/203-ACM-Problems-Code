/* Problem: Triangle Wave UVa 488
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 24-10-04
*/
#include <iostream.h>

void print(int n){
	int i, j;
	for (i = 1; i <= n; i++){
		for (j = 0; j < i; j++)
			cout << i;
		cout << endl;
	}
	for (i = n-1; i >= 1; --i){
		for (j = 0; j < i; j++)
			cout << i;
		cout << endl;
	}
}

int main(){
	int test;
	int amp, freq;
	int i, j, flag;

	flag = 0;
	cin >> test;

	for (i = 0; i < test; i++){
		cin >> amp >> freq;

		for (j = 0; j < freq; j++){
			if (flag) cout << endl;
			print(amp);
			flag = 1;
		}


	}


	return 0;
}
