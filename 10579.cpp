/* Problem: Fibonacci Numbers UVa 10579
   Programmer: Md. Mahmud Ahsan // Using Dynamic Programming (DP)
   Compiled: Visual C++ 6.0
   Date: 09-01-05
*/

#include <iostream>
#include <string>
using namespace std;

const int length = 5001;
char str[length][length];

void reverseStr(char *one);
char *bigSum(char *sFirst, char *sSecond);
//===============================================================
int main(){
	strcpy(str[0], "0");
	strcpy(str[1], "1");
	strcpy(str[2], "1");
	
	int i, input;
	for (i = 3; i < length; i++)
		strcpy(str[i], bigSum(str[i-1], str[i-2]));

	while (cin >> input){
		cout << str[input] << endl;
	}

	return 0;
}
//===============================================================
char *bigSum(char *sFirst, char *sSecond){
	char sSum[length];
	int firstLen, secondLen;
	int iFirst, iSecond, iSum;
	int carry;
	int t;

	// here the main calculation Begins
		carry = 0;
		t = 0;
		sSum[0] = '\0';
		firstLen = strlen(sFirst) - 1;
		secondLen = strlen(sSecond) - 1;

		while (firstLen >= 0 || secondLen >= 0){
			iFirst = sFirst[firstLen] - 48;
			iSecond= sSecond[secondLen] - 48;
			
			if (firstLen < 0) iFirst = 0;
			if (secondLen < 0) iSecond = 0;

			iSum = iFirst + iSecond + carry;
			
			if (iSum > 9)
				carry = 1;
			else
				carry = 0;
	
			sSum[t] = (iSum % 10) + 48;
			++t;
			--firstLen;
			--secondLen;
		}
		if (carry == 1){
			sSum[t] = carry + 48;
			sSum[++t] = '\0';
		}
		else
			sSum[t] = '\0';
		
		reverseStr(sSum);
		return sSum;
}

void reverseStr(char *one){
	char temp[length];
	int h = strlen(one) - 1;
	int i = 0;

	for (int j = h; j >= 0; j--){
		temp[i] = one[j];
		++i;
	}
	temp[i] = '\0'; // must set to null at last for "two" second string
	strcpy(one, temp);
}