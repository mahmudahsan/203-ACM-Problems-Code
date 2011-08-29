/* Problem:  Integer Inquiry  UVa 424
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 15-09-04
*/
// Summation Big Integer using string

#include <iostream>
#include <string>
using namespace std;

const int length = 200;
//prototypes
void reverseStr(char *one, char *two);

//=======================================================================
int main(){
	char sFirst[length], sSecond[length], sSum[length];
	int firstLen, secondLen;
	int iFirst, iSecond, iSum;
	int carry;
	int t;

	// all other lines added to the first line sFirst
	cin >> sFirst; 
	while (cin >> sSecond && sSecond[0] != '0'){
		carry = 0;
		t = 0;
		sSum[0] = '\0';
		firstLen = strlen(sFirst) - 1;
		secondLen = strlen(sSecond) - 1;

		// Individual digit used for sum
		while (firstLen >= 0 || secondLen >= 0){
			iFirst = sFirst[firstLen] - 48;
			iSecond= sSecond[secondLen] - 48;
			
			// if first or second's number length less than zero 
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
		// at last carry should be inserted to string
		if (carry == 1){
			sSum[t] = carry + 48;
			sSum[++t] = '\0';
		}
		else
			sSum[t] = '\0';

		// must be reversed
		reverseStr(sSum, sFirst);
	}
	cout << sFirst << endl;
	return 0;
}
//=========================================================================
void reverseStr(char *one, char *two){
	int h = strlen(one) - 1;
	int i = 0;

	for (int j = h; j >= 0; j--){
		two[i] = one[j];
		++i;
	}
	two[i] = '\0'; // must set to null at last for "two" second string
}