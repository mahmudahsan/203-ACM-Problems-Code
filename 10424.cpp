/* Problem: Love Calculator UVa 10424
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 28-08-04
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

// struct type contains the code value and character
struct initial{
	int value;
	char c;
};

// prototypes
void init(initial array[]);
int sum(int number);

//=================================================================
int main(){
	char firstString[30], secondString[30];
	initial array[26];
	int firstNumber, secondNumber;
	//numerator means lob, this is always small
	// opposite is denominator
	double numerator, denominator;
	double result;
	int i;
	//initialize
	init(array);
	
	while (!cin.eof()){
		firstNumber = secondNumber = 0;
		numerator = denominator = result = 0;
		
		cin.getline(firstString, sizeof(firstString));
		cin.getline(secondString, sizeof(secondString));

		// exit when eof encountered
		if (cin.eof()) break;

		// convert two string to lowercase
		for (i = 0; firstString[i]; i++)
			firstString[i] = tolower(firstString[i]);
		for (i = 0; secondString[i]; i++)
			secondString[i] = tolower(secondString[i]);
		
		// check character and sum the code
		for (i = 0; firstString[i]; i++){
			for (int j = 0; j < 26; j++){
				if (firstString[i] == array[j].c){
					firstNumber += array[j].value;
					break;
				}
			}
		}

		for (i = 0; secondString[i]; i++){
			for (int j = 0; j < 26; j++){
				if (secondString[i] == array[j].c){
					secondNumber += array[j].value;
					break;
				}
			}
		}

		// sum until it convert one digit
		do{
			firstNumber = sum(firstNumber);
		}while (firstNumber > 9);
			
		do{
			secondNumber = sum(secondNumber);
		}while (secondNumber > 9);
		

		// numerator must be less than denominator
		if (firstNumber > secondNumber){
			numerator = secondNumber;
			denominator = firstNumber;
		}
		else{
			numerator = firstNumber;
			denominator = secondNumber;
		}
		
		result = (numerator / denominator) * 100;
		printf("%.2lf %%\n", result);

	}

	return 0;
}
//====================================================================

//init initialize the array
void init(initial array[]){
	for (int i = 0; i < 26; i++){
		array[i].value = i + 1;
		array[i].c = i + 'a';
	}
}


int sum(int number){
	int _number = 0, temp;

	while (number != 0){
		temp = number % 10;
		_number += temp;
		number = number / 10;
	}
	return _number;
}