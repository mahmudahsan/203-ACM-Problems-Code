/* Problem: Decode the tape UVa 10878
   Programmer: Md. Mahmud Ahsan
   Description: Simulation, Ad hoc
   Compiled: Visual C++ 7.0
   Date: 21-02-06
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long convertBase10(char *str, int base){
	int len = strlen(str) - 1;
	int i, n;
	long number = 0;
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
		number = number + (n * pow((double)base, (double)len));
		--len;
	}
	return number;
}

void removes(char *str){
	char n[100], m[100];
	int i, j;
	j = 0;
	for (i = 0; str[i]; ++i){
		if (str[i] == ' '){
			n[j] = '0';
			++j;
		}
		else if (str[i] == 'o'){
			n[j] = '1';
			++j;
		}
	}
	n[j] = '\0';
	strcpy(str, n);
}

int main(){
	//freopen("input.txt", "r", stdin);
	char str[100], bin[100];
	long dec;

	while (cin.getline(str, sizeof(str))){
		if (str[0] == '|'){
			removes(str);
			dec = convertBase10(str, 2);
			cout << (char) dec;
		}	
	}

	return 0;
}
