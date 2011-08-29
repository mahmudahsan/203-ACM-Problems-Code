/* Problem: Product UVa 10106
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 04-10-04
*/
#include <iostream>
#include <string>
using namespace std;
 
const int length = 1000;
 
namespace global{
	// store the final summation after total multiplication
 	char sSum[length];
}
// prototypes
void reverseStr(char *one);
void bigSummation(char *sSecond);
//=====================================================================
int main(){
	// sFirst means first String, sSecond means second string
	char sFirst[length], sSecond[length], sTemp[length];
	int iFirst, iSecond;
	int firstLen, secondLen;
	int i, j, t, carry, temp, putZero;
	
	while (cin >> sFirst >> sSecond){
		global :: sSum[0] = '\0';
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

			bigSummation(sTemp);
		}
		bool flag = true; // use for checking zeros
		int tempLen = strlen(global :: sSum);
		for (i = 0; i < tempLen; i++){
			if (flag && global :: sSum[i] == '0')
				continue; // if zero leading
			else{ 
				flag = false;
				cout << global :: sSum[i];
			}
		}
		// flag is true when the result is only zero and one zero is printed 
		if (flag)
			cout << '0'; 
		cout << endl;
	}
	return 0;
}
//============================================================================
void reverseStr(char *one){
	char two[length];
	int len = strlen(one) - 1;
	int i;
	
	for (i = 0; i <= len; i++)
		two[i] = one[len - i];
	two[i] = '\0';
	strcpy(one, two);
}

void bigSummation(char *sSecond){
	char sFirst[length], sSum[length];
	int firstLen, secondLen;
	int iFirst, iSecond, iSum;
	int carry;
	int t;

	// copy sSum's data to sFirst 
	strcpy(sFirst, global :: sSum);
	firstLen = strlen(sFirst) - 1;
	secondLen = strlen(sSecond) - 1;

	carry = t = 0;
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
	
		// here sSum is local string
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
		strcpy(global :: sSum, sSum);
}