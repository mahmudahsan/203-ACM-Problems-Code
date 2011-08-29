/* Problem: Funny Encryption Method UVa 10019
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 26-11-04
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;


int countDecimal(int number);
int countHexa(int number);
void conDeciToHexa(char *number); // convert decimal to hexadecimal
//============================================================
int main(){
	int input;
	int number, decimal, hexa;
	cin >> input;

	for (int i = 0; i < input; i++){
		cin >> number;
		decimal = countDecimal(number);
		hexa = countHexa(number);
	
		cout << decimal << " " << hexa << endl;
	}
	return 0;
}
//===========================================================
int countDecimal(int number){
	vector <char> obj; 
	char temp;

	// algorithm procedure base b expansion
	while(number != 0){
		temp = (number % 2) + 48;
		obj.push_back(temp);
		number = number / 2;
	}

	int count = 0;
	for (int i = 0; i < obj.size(); i++){
		if (obj[i] == '1')
			count++;
	}
	return count;
}
//-----------------------------------------------
int countHexa(int number){
	vector <char> obj;
	int count = 0;
	char temp;
	char strNumber[100];
	
	// for facilities i send decimal number as string
	sprintf(strNumber, "%d", number);
	conDeciToHexa(strNumber); // convert decimal to hexa
	// finally i recover string to decimal
	sscanf(strNumber, "%d", &number);
	
	while (number != 0){
		temp = (number % 2) + 48;
		obj.push_back(temp);
		number = number / 2;
	}

	for (int i = 0; i < obj.size(); i++){
		if (obj[i] == '1')
			count++;
	}
	return count;
}
//--------------------------------------------
void conDeciToHexa(char *number){
	int len = strlen(number) - 1;	
	int temp = 0;
	int i = 0;

	// my algorithm;
	while (number[i]){
		temp = temp + (number[i] - 48) * pow(16, len);
		--len;
		++i;
	}
	sprintf(number, "%d", temp);
}