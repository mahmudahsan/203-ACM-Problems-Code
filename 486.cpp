/* Problem:  English-Number Translator  UVa 486
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 31-03-05
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	char data[31][100];

	strcpy(data[0], "one");		
	strcpy(data[1], "two");		
	strcpy(data[2], "three");	
	strcpy(data[3] , "four");		
	strcpy(data[4] , "five");		
	strcpy(data[5] , "six");		
	strcpy(data[6] , "seven");		
	strcpy(data[7] , "eight");	
	strcpy(data[8] , "nine");		
	strcpy(data[9] , "ten");		
	strcpy(data[10] , "eleven");	
	strcpy(data[11] , "twelve");	
	strcpy(data[12] , "thirteen");	
	strcpy(data[13] , "fourteen");	
	strcpy(data[14] , "fifteen");	
	strcpy(data[15] , "sixteen");	
	strcpy(data[16] , "seventeen");	
	strcpy(data[17] , "eighteen");	
	strcpy(data[18] , "nineteen");	
	strcpy(data[19] , "twenty");	
	strcpy(data[20] , "thirty");
	strcpy(data[21] , "forty");		
	strcpy(data[22] , "fifty");		
	strcpy(data[23] , "sixty");		
	strcpy(data[24] , "seventy");	
	strcpy(data[25] , "eighty");	
	strcpy(data[26] , "ninety");	
	strcpy(data[27] , "hundred");	
	strcpy(data[28] , "thousand");	
	strcpy(data[29] , "million");	
	strcpy(data[30] , "negative");  
	
	int value, million, thousand, hundred, sign;
	
	char input[300];
	char *ptr;
	
	while (cin.getline(input, sizeof(input))){
		value = sign = 0;
		million = thousand = 1;

		ptr = strtok(input, " \n\t\r");

		while (ptr){

			for(int i = 0; i < 31; ++i){
				if (strcmp(data[i], ptr) == 0){
					if (i == 0)
						value += 1;
					else if (i == 1)
						value += 2;
					else if (i == 2)
						value += 3;
					else if (i == 3)
						value += 4;
					else if (i == 4)
						value += 5;
					else if (i == 5)
						value += 6;
					else if (i == 6)
						value += 7;
					else if (i == 7)
						value += 8;
					else if (i == 8)
						value += 9;
					else if (i == 9)
						value += 10;
					else if (i == 10)
						value += 11;
					else if (i == 11)
						value += 12;
					else if (i == 12)
						value += 13;
					else if (i == 13)
						value += 14;
					else if (i == 14)
						value += 15;
					else if (i == 15)
						value += 16;
					else if (i == 16)
						value += 17;
					else if (i == 17)
						value += 18;
					else if (i == 18)
						value += 19;
					else if (i == 19)
						value += 20;
					else if (i == 20)
						value += 30;
					else if (i == 21)
						value += 40;
					else if (i == 22)
						value += 50;
					else if (i == 23)
						value += 60;
					else if (i == 24)
						value += 70;
					else if (i == 25)
						value += 80;
					else if (i == 26)
						value += 90;
					else if (i == 27){
						value = value * 100;
					}
					else if (i == 28){
						thousand = value * 1000;
						value = 0;
					}
					else if (i == 29){
						million = value * 1000000;
						value = 0;
					}
					
					if (i == 30)
						sign = 1;
					break;
					}// endif
				}// end for loop
				ptr = strtok(NULL," \n\t\r");
			}// end inner while
			
			if (million > 1)
				value += million;
			if (thousand > 1)
				value += thousand;
			
			if (sign)
				cout << "-" << value << endl;
			else
				cout << value << endl;
		}
		return 0;
	}

						
		
