/* Problem: Super long sums UVa 10013
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 15-09-04
*/

#include <iostream>
#include <string>
using namespace std;

const int length = 1000020;
typedef long int lint;

//prototypes
void reverseStr(char *one);

//========================================================================
int main(){
	char sFirst[length], sSecond[length], sSum[length];
	lint firstLen, secondLen;
	lint iFirst, iSecond, iSum, carry; 

	lint test;
	lint M;
	lint i, t; // for counter
	bool flag = false; // for output

	cin >> test;
	for (lint term = 0; term < test; term++){
		
		cin >> M;
		for (i = 0; i < M; i++)
			cin >> sFirst[i] >> sSecond[i];
		
		sFirst[i] = sSecond[i] = '\0';
		t = carry = 0;
		sSum[0] = '\0';

		firstLen = strlen(sFirst) - 1;
		secondLen = strlen(sSecond) - 1;

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
		
		
		reverseStr(sSum);
		if (flag) cout << "\n";
		cout << sSum << endl;
		flag = true;
	}
	return 0;
}
//========================================================================
void reverseStr(char *one){
	char two[length];

	lint h = strlen(one) - 1;
	lint i = 0;

	for (lint j = h; j >= 0; j--){
		two[i] = one[j];
		++i;
	}
	two[i] = '\0'; // must set to null at last for "two" second string
	strcpy(one, two);
}