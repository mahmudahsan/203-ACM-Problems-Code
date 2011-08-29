/* Problem: Factors and Factorials UVa 160
   Programmer: Md. Mahmud Ahsan
   Description: !50 = 50.49.48...., seive, prime factor
   Compiled: Visual C++ 7.0
   Date: 10-06-05
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

char seive[104];
int prm[40];
int k;
void genSeive(){
	seive[0] = seive[1] = 1;
	int i, j;
	for (i = 2; i < sqrt( (double) 104); ++i){
		if (!seive[i])
			for (j = i + i; j < 104; j += i)
				seive[j] = 1;
	}
	int k = -1;
	for (i = 0; i < 104; ++i){
		if (!seive[i])
			prm[++k] = i;
	}
	::k = k;
}

int main(){
	genSeive();
	int i, j, temp;
	int array[101];

	int input;
	while (cin >> input){
		if (!input) break;

		for (i = 0; i < 101; ++i)
			array[i] = 0;
		
		int flag;
		for (i = input; i > 1; --i){
			temp = i;
			if (!seive[temp]){
				array[temp] += 1;
				continue;
			}
			for (j = 0; j <= k; ){
				if (temp % prm[j]==0 ){
					++array[prm[j]];
					temp = temp / prm[j];
					continue;
				}
				++j;
			}
		}
		int count = 1;
		printf("%3d! =", input);
		for (i = 0; i < 101; ++i){
			if (array[i] != 0 && count != 16){
				printf("%3d", array[i]);
				++count;
			}
			else if (array[i] != 0 && count == 16){
				printf("\n%9d", array[i]);
				count = 1;
			}
		}
		cout << endl;
	}
	return 0;
}
