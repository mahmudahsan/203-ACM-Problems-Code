/* Problem: What Base Is This? UVa 343
   Programmer: Md. Mahmud Ahsan
   Description: Base Conversion
   Compiled: Visual C++ 7.0
   Date: 13-08-05
*/
#include <iostream>
#include <string>
using namespace std;

long long myPow(long long number, long long power){
	long long total=1;
	for (long long i = 0; i < power; ++i)
		total *= number;
	return total;
}


long long otherToDec(char *str, int base){
	int len = strlen(str) - 1;
	int alpha[100];
	long long i, number, j=9; // j for alphabetical base digit
	for (i = 65; i < 65+26; ++i){
		alpha[i] = ++j; // collect numeric data suppose A=10
	}

	number = 0;
	for (i = 0; str[i]; ++i){
		if (str[i] >= 'A' && str[i] <= 'Z')
			j = alpha[str[i]];
		else 
			j = str[i] - 48;
		number += j * myPow(base, len);
		--len;
	}
	return number;
}


// this method returns minimum base for a given number
int minBase(char *str){
	int alpha[100];
	int i, number, max, j=9; // j for alphabetical base digit
	for (i = 65; i < 65+26; ++i){
		alpha[i] = ++j; // collect numeric data suppose A=10
	}

	number = max= 0;
	for (i = 0; str[i]; ++i){
		if (str[i] >= 'A' && str[i] <= 'Z')
			j = alpha[str[i]];
		else 
			j = str[i] - 48;
		if (j > max)
			max = j;
	}
	if (max == 0) return 2;

	return max+1;
}

int main(){
	char str1[100], str2[100];
	char con1[100], con2[100];
	long long dec1, dec2;
	int i, j, flag;

	while (cin >> str1 >> str2){
		flag = 0;
		for (i = minBase(str1); i <= 36; ++i){
			for (j = minBase(str2); j <= 36; ++j){
				dec1 = otherToDec(str1, i);
				dec2 = otherToDec(str2, j);
				
				if (dec1 == dec2){
					flag = 1;
					cout << str1 << " (base " << i << ") = " << str2 << " (base " << j << ")" << endl;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (!flag)
			cout << str1 << " is not equal to " << str2 << " in any base 2..36" << endl;

	}
	return 0;
}