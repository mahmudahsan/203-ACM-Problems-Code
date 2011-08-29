/* Problem: What's The Frequency, Kenneth?  UVa 499
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 10-10-04
*/
#include <iostream>
#include <string>
using namespace std;

// prototypes
void initialize(char code[][2], int &a);
int getMax(char array[][2]);

//===========================================================================
int main(){
	char code[52][2];
	char str[100];
	int max;
	int i, j;
	int temp;

	while (cin.getline(str, sizeof(str)) && !cin.eof()){
		// if blank line is inputed
		if (strlen(str) == 0)  continue;
		
		// initialization
		initialize(code, max);
		
		//search letters frequency
		for (i = 0; str[i]; i++){
			for (j = 0; j < 52; j++){
				if (str[i] == code[j][0]){
					code[j][1] += 1;
					break;
				}
			}
		}

		max = getMax(code);
		// output the letter that occurs maximum
		for (i = 0; i < 52; i++){
			temp = code[i][1] - 48;
			if (max == temp)
				cout << code[i][0];
		}
		// output the max 
		cout << " " << max << endl;
	}
	
	return 0;
}
//===========================================================================

void initialize(char code[][2], int &a){
	int i;
	a = 0;

	for (i = 0; i < 26; i++){
		code[i][0] = 'A' + i;
		code[i][1] = '0';
	}

	for (i = 0; i < 26; i++){
		code[i + 26][0] = 'a' + i;
		code[i + 26][1] = '0';
	}
}

int getMax(char array[][2]){
	int max, temp;
	int i;

	max = 0;
	for (i = 0; i < 52; i++){
		temp = array[i][1] - 48;
		if (max < temp)
			max = temp;
	}
	return max;
}