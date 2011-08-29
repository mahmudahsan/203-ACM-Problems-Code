/* Problem: 500! UVa 623
   Programmer: Md. Mahmud Ahsan // Using Dynamic Programming (DP)
   Compiled: Visual C++ 6.0
   Date: 09-01-05
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int length = 10000;

char str[1001][length];

void reverseStr(char *one);
char *bigSum(char *sFirst, char *sSecond);
char *bigMult(char *sFirst, char *sSecond);
//=======================================================================
int main(){
	int i, input;
	char tmpStr[length];

	strcpy(str[0], "1");
	strcpy(str[1], "1");

	for (i = 2; i < 1001; i++){
		sprintf(tmpStr, "%d", i);
		strcpy(str[i], bigMult(str[i-1], tmpStr));
	}
	 
	while (cin >> input){
		cout << input << "!" << endl;
		cout << str[input] << endl;
	}
	return 0;
}
//========================================================================
char *bigMult(char *sFirst, char *sSecond){
// sFirst means first String, sSecond means second string
	char sTemp[length], sSum[length], sFinal[length];
	int iFirst, iSecond;
	int firstLen, secondLen;
	int i, j, t, carry, temp, putZero;
	
	// main calculation begins here
		sSum[0] = '\0';
		sTemp[0] = '\0';
			
		firstLen = strlen(sFirst) - 1;
		secondLen = strlen(sSecond) - 1;
		
	    // putZero used for to add zero after multiplication when addition is needed
	   // zero add to the empty space at right side after the first multiplicaton row
		putZero = -1;
		for (i = secondLen; i >= 0; --i){
		//sTemp used for a new multiplication for a line suppose 22 * 3 = 66
		// here  sTemp contains 66
			sTemp[0] = '\0';
			carry = t = 0;
			
			iSecond = sSecond[i] - 48;
			for (j = firstLen; j >= 0; --j){
				iFirst = sFirst[j] - 48;
				temp = (iFirst * iSecond) + carry;
				
				if (temp <= 9)
					carry = 0;
				else if (temp >= 10 && temp <= 19)
					carry = 1;
				else
					carry = temp / 10;
				
				sTemp[t++] = (temp % 10) + 48; 
			}
			sTemp[t] = '\0';
			++putZero;
					
			if (carry > 0){
				sTemp[t] = carry + 48;
				sTemp[++t] = '\0';
				
			}
			else
				sTemp[t] = '\0';
			
			// after putting carry string must be reversed	
			reverseStr(sTemp);			
			
			// if two or more lines, zero added [11 * 3] =  33 + 330
			for (int k = 0; k < putZero; k++)
				sTemp[t++] = '0';
			sTemp[t] = '\0';
			strcpy (sSum, bigSum(sSum, sTemp));
		}
		bool flag = true; // use for checking zeros
		int sSumLen = strlen(sSum);
		int kk = -1; // use for sFinal
		sFinal[0] = '0';
		

		for (i = 0; i < sSumLen; i++){
			if (flag && sSum[i] == '0')
				continue; // if zero leading
			else{ 
				flag = false;
				sFinal[++kk] = sSum[i];
			}
		}
		
		if (flag)
			sFinal[1] = '\0';
		else 
			sFinal[++kk] = '\0';
		
		return sFinal;
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