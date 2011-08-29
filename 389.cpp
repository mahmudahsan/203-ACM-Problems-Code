/* Problem:  Basically Speaking  UVa 389
   Programmer: Md. Mahmud Ahsan
   Description: BASE CONVERSION
   Compiled: Visual C++ 7.0
   Date: 04-07-05
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef long lint;

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
	char str[100], c;
	int i;
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

int main(){
	//freopen("output.txt", "w", stdout);
	int bFrom, bTo ;
	lint number;
	char input[100], output[100];
	bool flag;

	while (cin >> input >> bFrom >> bTo){
		cout.width(7);
		cout.setf(ios :: right);

		flag = 0;
		for (int i = 0; input[i]; ++i){
			if (input[i] != '0')
				flag = 1;
		}
		
		if (!flag){
			cout << 0 << endl;
			continue;
		}

		number = convertBase10(input, bFrom);
		strcpy(output, convertBaseOther(number, bTo));
		
		if (strlen(output) > 7){
			cout << "ERROR" << endl;
			continue;
		}
		cout << output << endl;
	}
}