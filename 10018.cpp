/* Problem: Reverse and Add UVa 10018
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-09-04
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef unsigned long int lint;

// namespace global for use all the function
namespace global{
	bool palin;
	int count;
	char strFirst[100], strSecond[100], strSum[100];
	lint iFirst, iSecond, iSum;
}

// prototypes
void reverseStr(char *one, char *two);
bool chkPalin(char *str);
void calculation(char *);

//=======================================================================
int main(){
	char strInput[100];
	int test;
	cin >> test;
	for (int t = 0; t < test; t++){
		using namespace global;
		
		// each time set main terms to default terms
		palin = false;
		count = 0;
		iSum = iFirst = iSecond = 0;

		cin >> strInput;
		calculation(strInput); // calculate and print	
	}
	return 0;
}
//=======================================================================
void reverseStr(char *one, char *two){
	int h = strlen(one) - 1;
	int i = 0;

	for (int j = h; j >= 0; j--){
		two[i] = one[j];
		++i;
	}
	two[i] = '\0'; // must set to null at last for "two" second string
}

bool chkPalin(char *str){
	int high = strlen(str) - 1;
	int middle = strlen(str) / 2;

	for (int low = 0; low < middle; low++){
		if (str[low] != str[high - low])
			return false;
	}
	return true;
}

void calculation(char *strFirst){
	using namespace global;

	if (chkPalin(strFirst)){
		cout << "0" << " " << strFirst << endl;
		return;
	}

	do{
		count++;
		reverseStr(strFirst, strSecond);
		sscanf(strFirst, "%lu", &iFirst);
		sscanf(strSecond, "%lu", &iSecond);
		iSum = iFirst + iSecond;
		sprintf(strSum, "%lu", iSum);
		strcpy(strFirst, strSum);
	}while (!chkPalin(strSum));
	cout << count << " " << strSum << endl;
}