/* Problem: Leap Year or Not Leap Year and..UVa 10070
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 03-01-05
*/

#include <iostream>
#include <string>
using namespace std;

const long length = 10000;

char str[length]; // input 
long len; // input length

bool leapYear, huluculu, buluculu;

// prototypes
void chkLeapYear();
void chkHuluculu();
void chkBuluculu();

//===================================================================
int main(){
	bool newLine = false;
	while (cin >> str){
		len = strlen(str) - 1;
		leapYear = huluculu = buluculu = false;

		chkLeapYear(); chkHuluculu(); chkBuluculu();

		if (newLine) cout << endl;

		if (!leapYear && !huluculu && !buluculu){
			cout << "This is an ordinary year." << endl;
			continue;
		}
		if (leapYear)
			cout << "This is leap year." << endl;
		if (huluculu)
			cout << "This is huluculu festival year." << endl;
		if (buluculu)
			cout << "This is bulukulu festival year." << endl;
		
		if(!newLine) newLine = true;
	}
	return 0;
}
//===================================================================
void chkLeapYear(){
	bool four = false, hundred = false, fourHundred = false;
	int last, bfLast, lastTwo;
	
	last = str[len] - 48;
	bfLast = str[len-1] - 48;

	lastTwo = last + (bfLast * 10);

	if (lastTwo == 0){
		four = true;
		hundred = true;
	}
	else if (lastTwo % 4 == 0)
		four = true;

	if (lastTwo == 0){
		last = str[len-2] - 48;
		bfLast = str[len-3] - 48;
		lastTwo = last + (bfLast * 10);

		if ((lastTwo == 0) || (lastTwo % 4 == 0))
			fourHundred = true;
	}

	if ((four && !hundred) || fourHundred)
		leapYear = true;
}

void chkHuluculu(){
	long sum = 0, last;
	bool three = false, five = false;
	
	for (int i = 0; str[i]; i++)
		sum = sum + (str[i] - 48);

	if (sum % 3 == 0)
		three = true;
	
	last = str[len] - 48;
	if (last == 0 || last == 5)
		five = true;
	
	if (three && five)
		huluculu = true;
}

void chkBuluculu(){
	bool five = false, eleven = false;
	long sum = str[0] - 48;
	int last = str[len] - 48;

	if (last == 0 || last == 5) 
		five = true;

	bool plusMinus = false;
	for (int i = 1; str[i]; i++){
		if (plusMinus){
			sum = sum + (str[i] - 48);
			plusMinus = !plusMinus;
		}
		else{
			sum = sum - (str[i] - 48);
			plusMinus = !plusMinus;
		}
	}
	if (sum % 11 == 0)
		eleven = true;

	if (five && eleven && leapYear)
		buluculu = true;
}