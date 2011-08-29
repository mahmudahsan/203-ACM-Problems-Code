/* Problem: Palindromes UVa 401
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 25-08-04
*/

#include <iostream>
#include <string>
using namespace std;

// prototypes
bool palindrome(char *string, int size);
bool mirror(char *strFirst);

//=================================================================
int main(){
	char str[100];
	bool mirFlag, palinFlag;

	while (cin >> str){
		mirFlag = palinFlag = false; // for a new start
		
		palinFlag = palindrome(str, strlen(str));
		mirFlag = mirror(str);

		if (palinFlag == false && mirFlag == false)
			cout << str << " -- is not a palindrome." << endl << endl;
		else if (palinFlag == true && mirFlag == false)
			cout << str << " -- is a regular palindrome." << endl << endl;
		else if (palinFlag == false && mirFlag == true)
			cout << str << " -- is a mirrored string." << endl << endl;
		else if (palinFlag == true && mirFlag == true)
			cout << str << " -- is a mirrored palindrome." << endl << endl;
	}
	return 0;
}
//=================================================================

bool palindrome(char *string, int size){
	// the palindrome algorithm
	int n = size / 2;
	int newSize = size - 1; // as the array starts with 0
	for (int i = 0; i < n; i++){
		if (string[i] != string[newSize - i])
			return false;
	}
	return true;
}

bool mirror(char *strFirst){
	char mir[21][2];
	char strSecond[50];
	//initialized
	mir[0][0] = 'A'; mir[0][1] = 'A';
	mir[1][0] = 'E'; mir[1][1] = '3';
	mir[2][0] = 'H'; mir[2][1] = 'H';
	mir[3][0] = 'I'; mir[3][1] = 'I';
	mir[4][0] = 'J'; mir[4][1] = 'L';
	mir[5][0] = 'M'; mir[5][1] = 'M';
	mir[6][0] = 'O'; mir[6][1] = 'O';
	mir[7][0] = 'S'; mir[7][1] = '2';
	mir[8][0] = 'T'; mir[8][1] = 'T';
	mir[9][0] = 'U'; mir[9][1] = 'U';
	mir[10][0] = 'V'; mir[10][1] = 'V';
	mir[11][0] = 'W'; mir[11][1] = 'W';
	mir[12][0] = 'X'; mir[12][1] = 'X';
	mir[13][0] = 'Y'; mir[13][1] = 'Y';
	mir[14][0] = 'Z'; mir[14][1] = '5';
	mir[15][0] = '1'; mir[15][1] = '1';
	mir[16][0] = '2'; mir[16][1] = 'S';
	mir[17][0] = '3'; mir[17][1] = 'E';
	mir[18][0] = '5'; mir[18][1] = 'Z';
	mir[19][0] = '8'; mir[19][1] = '8';
	mir[20][0] = 'L'; mir[20][1] = 'J';

	int i, row;
	for (i = 0; strFirst[i] != '\0'; i++){
		char c = strFirst[i]; // single character
		for (row = 0; row < 21; row++){
			if (mir[row][0] == c){
				strSecond[i] = mir[row][1];
				break;
			}
		}
	}
	strSecond[i] = '\0'; // must be set to null

	// for comparing purpose as j initialized to zero and an array begins zero
	int len = strlen(strFirst) - 1;
	for (int j = 0; j <= len; j++){
		if (strFirst[j] != strSecond[len - j])
		return false;
	}
	return true;
}