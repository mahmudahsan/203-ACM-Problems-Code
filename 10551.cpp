/* Problem: Basic remains  UVa 10551
   Programmer: Md. Mahmud Ahsan
   Description: Base Conversion + Moduler Arithmetic
   Compiled: Visual C++ 7.0
   Date: 16-09-05
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef long long lint;

lint pow(int b, int n, lint mod){
	lint num = 1;
	for (int i = 0; i < n; ++i){
		num = num * b;
		num = num % mod;
	}
	return num;
}

lint convertBase10(char *str, int base, lint mod){
	int len = strlen(str) - 1;
	int i, n;
	lint number = 0;
	for (i = 0; str[i]; ++i){
		switch(str[i]){
			case 'a':
			case 'A': n = 10; break;
			case 'b':
			case 'B': n = 11; break;
			case 'c':
			case 'C': n = 12; break;
			case 'd': 
			case 'D': n = 13; break;
			case 'e':
			case 'E': n = 14; break;
			case 'f':
			case 'F': n = 15; break;
			default: n = str[i]-48;
		}
		number =  number + (n * pow(base, len, mod));
		number = number % mod;
		--len;
	}
	return number;
}

void revStr(char *str){
	char temp[100];
	int len = strlen(str) - 1;
	int i;
	for (i = 0; str[i]; ++i){
		temp[i] = str[len-i];
	}
	temp[i] = '\0';
	strcpy(str, temp);
}

char* decToOther(int number, int base){
	char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char final[100];
	int n, temp, j;

	j = -1;
	do{
		temp = number % base;
		final[++j] = str[temp];
		number = number / base;
	}while (number != 0);
	final[++j] = '\0';
	revStr(final);
	return final;
}

int main(){
	int b;
	lint mod, final;
	char num[2000], _mod[100], res[2000];

	while (cin >> b){
		if (b == 0) break;
		
		cin >> num >> _mod;

		mod = convertBase10(_mod, b, 999999999);
		final = convertBase10(num, b, mod);
		
		//special case
		if (mod == 1){
			cout << 0 <<  endl;
			continue;
		}

		strcpy(res, decToOther(final, b));
		cout << res << endl;
	}

	return 0;
}