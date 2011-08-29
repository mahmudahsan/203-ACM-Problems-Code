/* Problem: Last Digit UVa 10162
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 09-09-04
*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	int ld[101];
	long int r, x;

	int i, j;

	ld[0] = 0;

	for (i = 1; i <= 100; i++){
		r = x = i % 10;
		for (j = 1; j < i; j++)
			r = (r * x) % 10;

		
		ld[i] = r + ld[i-1];
		ld[i] %= 10;
	}
	
	char str[5000];
	long int n;

	while (cin >> str){
		if (str[0] == '0') break;
		
		i = 0;
		j = strlen(str);

		if (j > 2) 
			i = j - 2;
		sscanf(&str[i], "%d", &n);

		cout << ld[n] << endl;
	}
	return 0;
}