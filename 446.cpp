/* Problem: Kibbles `n' Bits `n' Bits `n' Bits UVa 446
   Programmer: Md. Mahmud Ahsan
   Description: hex, binary to decimal, number conversion
   Compiled: Visual C++ 7.0
   Date: 10-06-05
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

void revStr(char *str){
	int i, len;
	len = strlen(str)-1;
	char st[100];
	for (i = 0; i <= len; ++i){
		st[i] = str[len-i];
	}
	st[i] = '\0';
	strcpy(str, st);
}

int main(){
	int a, b, sum, i, j, n;
	long binA, binB, temp;
	char c, strA[100], strB[100];
	cin >> n;
	for (i = 0; i < n; ++i){
		cin >> hex >> a;
		cin >> c;
		cin >> hex >> b;		
		
		if (c == '+')sum = a + b;
		else if (c == '-') sum = a - b;

		binA = binB = 0;
		j = -1;
		do{
			temp = a % 2;
			a = a / 2;
			strA[++j] = temp+48;
		}while (a != 0);
		strA[++j] = '\0';
		revStr(strA);
		j = -1;
		do{
			temp = b % 2;
			b = b / 2;
			strB[++j] = temp+48;
		}while (b != 0);
		strB[++j] = '\0';
		revStr(strB);
		
		//printf("%013s\n", strA);
		cout << setfill('0') << setw(13) << strA << " " << c << " ";
		cout << setfill('0') << setw(13) << strB << " = " << sum << endl;
	}

	return 0;
}