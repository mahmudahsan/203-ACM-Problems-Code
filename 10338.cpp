/* Problem: Mischievous Children UVa 10338
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 18-03-05
*/ 
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef long double ld;

ld factorial(int n){
	ld total = 1;
	for (int i = n; i > 0; --i)
		total = total * i;

	return total;
}

void init(int array[][2]){
	int i;
	for (i = 65; i < 91; i++){
		array[i][0] = i;
		array[i][1] = 0;
	}
}

void search(char *str, int array[][2]){
	int len, i, j;
	len = strlen(str);

	for (i = 0; i < len; i++){
		for (j = 65; j < 91; j++){
			if (str[i] == array[j][0])
				array[j][1] = array[j][1] + 1;
		}
	}
}

int main(){
	char str[100];
	int array[92][2];

	int limit, len, j;
	ld result;

	cin >> limit;
	for (int i = 0; i < limit; ++i){
		cin >> str;
	
		init(array);
		search(str, array);
		len = strlen(str);
		result = factorial(len);

		for (j = 65; j < 91; ++j){
			if (array[j][1] != 0)
				result = result / factorial(array[j][1]);
		}

		
		cout << "Data set " << i+1 << ": ";
		printf("%.0llf\n", result);

	}
	return 0;
}