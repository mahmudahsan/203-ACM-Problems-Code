/* Problem:  The Bases Are Loaded UVa 355
   Programmer: Md. Mahmud Ahsan
   Description: BASE CONVERSION
   Compiled: Visual C++ 7.0
   Date: 04-07-05
*/
#include <iostream>
#include <string>
using namespace std;

typedef long long lint;

lint pow(int b, int n){
	lint num = 1;
	for (int i = 0; i < n; ++i)
		num = num * b;
	return num;
}

lint convertBase10(char *str, int base){
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
		number = number + (n * pow(base, len));
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

char* convertBaseOther(lint number, int base){
	if (number == 0)
		return "0";
	char str[100], c;
	int i, j;
	lint temp;
	i = -1;
	while (number != 0){
		temp = number % base;
		number = number / base;

		switch(temp){
			case 10: c = 'A'; break;
			case 11: c = 'B'; break;
			case 12: c = 'C'; break;
			case 13: c = 'D'; break;
			case 14: c = 'E'; break;
			case 15: c = 'F'; break;
			default: c = temp + 48;
		}
		str[++i] = c;
	}
	str[++i] = '\0';
	revStr(str);
	return str;
}

int chkValid(char *str, int b){
	int n, i;
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
		if (n >= b) return 0;
	}
	return 1;
}

int main(){
	int bFrom, bTo ;
	lint number;
	char input[100], output[100];
	int n;

	while (cin >> bFrom >> bTo >> input){
		n = chkValid(input, bFrom);
		if (n == 0){
			cout << input << " is an illegal base " << bFrom << " number" << endl;
			continue;
		}
		number = convertBase10(input, bFrom);
		strcpy(output, convertBaseOther(number, bTo));
		cout << input << " base " << bFrom << " = " << output << " base " << bTo << endl;	
	}
}