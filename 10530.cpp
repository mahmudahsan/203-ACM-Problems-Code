/* Problem: Guessing Game UVa 10530
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 09-10-04
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	int array[11];
	int guess;
	char strA[30];
	char strB[30];
	int i;
	bool flag = true;
	
	// when need a integer input and a string input line by line
	// then it's better to use two getline()
	while(cin.getline(strA, sizeof(strA))){

		if (strlen(strA) == 2)
			guess = 10;
		else
			guess = strA[0] - 48;

		if (guess == 0)
			break;
		cin.getline(strB, sizeof(strB)); // input second line

		if (flag){
			for (i = 1; i <= 10; i++)
				array[i] = 1;
			flag = false;
		}


		if (strcmp(strB, "too high") == 0){
			for (i = guess; i <= 10; ++i)
				array[i] = 0;
		}
		else if (strcmp(strB, "too low") == 0){
			for (i = guess; i >= 1; --i)
				array[i] = 0;
		}
		else if (strcmp(strB, "right on") == 0){
			flag = true;
			if (array[guess] == 1)
				cout << "Stan may be honest" << endl;
			else
				cout << "Stan is dishonest" << endl;
		}
	}
	return 0;
}